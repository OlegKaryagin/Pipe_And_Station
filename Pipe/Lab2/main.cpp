#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Utils.h"
#include "CPipe.h"
#include "CStation.h"

using namespace std;

void EditPipeGroup (const vector <int>& selects_pipes, unordered_map<int,CPipe>& pipe)
{
	for (int i = 0; i < selects_pipes.size(); i++)
	{
		pipe[selects_pipes[i]].EditPipe();
	}
}

void EditGroup(unordered_map<int, CPipe>& pipe)
{
	string help_str;
	vector <int> pipes_for_edit;
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the pipes id: (by spaces)" << endl;
		getline(cin, help_str);
	} while (cin.fail());
	for (int i = 0; i < help_str.size(); i++)
		if (help_str[i] != ' ')
			pipes_for_edit.push_back(help_str[i] - '0');
	EditPipeGroup(pipes_for_edit, pipe);
}

void EditPipeInterval(unordered_map<int, CPipe>& pipe, int min, int max)
{
	if (min > max)
		swap(min, max);
	for (int i = min; i <= max; i++)
		pipe[i].EditPipe();
}

void EditStationGroup(const vector <int>& selects_stations, unordered_map<int, CStation>& station)
{
	int work;
	cout << "Enter number of workshops in work" << endl;
	work = GetCorrectNumber(0,100);
	for (int i = 0; i < selects_stations.size(); i++)
	{
		if(work < station[selects_stations[i]].num_workshop)
			station[selects_stations[i]].num_workshop_in_work = work;
	}
}

void EditGroupS(unordered_map<int, CStation>& station)
{
	string help_str;
	vector <int> stations_for_edit;
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the stationss id: (by spaces)" << endl;
		getline(cin, help_str);
	} while (cin.fail());
	for (int i = 0; i < help_str.size(); i++)
		if (help_str[i] != ' ')
			stations_for_edit.push_back(help_str[i] - '0');
	EditStationGroup(stations_for_edit, station);
}

void EditStationInterval(unordered_map<int, CStation>& station, int min, int max)
{
	int work;
	cout << "Enter number of workshops in work" << endl;
	work = GetCorrectNumber(0, 100);
	if (min > max)
		swap(min, max);
	for (int i = min; i <= max; i++)
		if (work < station[i].num_workshop)
			station[i].num_workshop_in_work = work;
}

vector<int> FindByDiametr(const unordered_map<int, CPipe>& pipe, int param)
{
	vector <int> selected_pipes;
	selected_pipes.reserve(pipe.size());
	for (const auto& present_pipe : pipe)
	{
		if (present_pipe.second.GetDiametr() >= param)
			selected_pipes.push_back(present_pipe.first);
	}
	return selected_pipes;
}

vector<int> FindByStatus(const unordered_map<int, CPipe>& pipe, bool param)
{
	vector <int> selected_pipes;
	selected_pipes.reserve(pipe.size());
	for (const auto& present_pipe : pipe)
	{
		if (present_pipe.second.status == param)
			selected_pipes.push_back(present_pipe.first);
	}
	return selected_pipes;
}

vector<int> FindByName(const unordered_map<int, CStation>& station, string name)
{
	vector <int> selected_stations;
	selected_stations.reserve(station.size());
	for (const auto& present_station : station)
	{
		if (present_station.second.name == name)
			selected_stations.push_back(present_station.first);
	}
	return selected_stations;
}

vector<int> FindByPercent(const unordered_map<int, CStation>& station, double percent)
{
	double percent_workshop;
	vector <int> selected_stations;
	selected_stations.reserve(station.size());
	for (const auto& present_station : station)
	{
		percent_workshop = 100 * ((double)present_station.second.num_workshop_in_work / present_station.second.num_workshop);
		if (percent_workshop >= percent)
			selected_stations.push_back(present_station.first);
	}
	return selected_stations;
}

void MainMenu()
{
	cout << "1.New pipe." << endl
		<< "2. Print pipe." << endl
		<< "3. Save pipe." << endl
		<< "4. Load pipe." << endl
		<< "5.Find pipe by diametr." << endl
		<< "6. Find pipe by status." << endl
		<< "7. Edit pipe." << endl
		<< "8. Edit pipe group." << endl
		<< "9. Delete pipe." << endl
		<< "10.New station." << endl
		<< "11. Print station." << endl
		<< "12. Save station." << endl
		<< "13. Load station." << endl
		<< "14.Find station by name." << endl
		<< "15. Find station by percent." << endl
		<< "16. Edit station." << endl
		<< "17. Edit station group." << endl
		<< "18. Delete station." << endl
		<< "0. Exit." << endl;
}

int main()
{
	unordered_map <int, CPipe> pipe;
	unordered_map <int, CStation> station;
	while (1)
	{
		MainMenu();
		switch (GetCorrectNumber(0, 18))
		{
			case 1:
			{
				pipe.insert(make_pair(CPipe::MID, CPipe()));
				break;
			}
			case 2:
			{
				for (auto it = pipe.begin(); it != pipe.end(); it++)
					cout << it->second << endl;
				break;
			}
			case 3:
			{
				fstream fout;
				string filename;
				cout << "Save file name: ";
				cin >> filename;
				fout.open(filename + ".txt", fstream::out);
				if (fout.is_open())
				{
					for (auto it = pipe.begin(); it != pipe.end(); ++it)
					{
						fout << it->second << endl;
					}
				}
				fout.close();
				break;
			}
			case 4:
			{
				fstream fin;
				unordered_map<int, CPipe> pipe2;
				string filename;
				cout << "Load file name: ";
				cin >> filename;
				fin.open(filename + ".txt", fstream::in);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						CPipe preset_pipe(fin);
						pipe2.insert(make_pair(preset_pipe.GetID(), preset_pipe));
					}
					fin.close();
					pipe = pipe2;
					CPipe::MID = FindMaxID(pipe);
				}
				else { cout << "error"; }
				break;
			}
			case 5:
			{
				int diametr;
				cout << "Enter diametr" << endl;
				diametr = GetCorrectNumber(1,10000);
				for (int i : FindByDiametr(pipe, diametr))
				{

					cout <<pipe[i] << endl;
				}
				cout << "Do you want edit this pipes?" << endl;
				bool answer;
				answer = GetCorrectNumber(0, 1);
				if (answer == true)
				{
					for (int i : FindByDiametr(pipe, diametr))
						pipe[i].EditPipe();
				}
				else { break; }
			}
			case 6:
			{
				bool status;
				cout << "Enter status" << endl;
				cin >> status;
				for (int i : FindByStatus(pipe, status))
				{

					cout << pipe[i] << endl;
				}
				cout << "Do you want edit this pipes?" << endl;
				bool answer;
				answer = GetCorrectNumber(0, 1);
				if (answer == true)
				{
					for (int i : FindByStatus(pipe, status))
						pipe[i].EditPipe();
				}
				else { break; }
			}
			case 7:
			{
				int id = GetCorrectNumber(1, 1000);
				pipe[id].EditPipe();
				break;
			}
			case 8:
			{
				bool answer;
				cout << "1.Edit interval of pipes" << endl
					<< "0.Edit group of pipes" << endl;
				answer = GetCorrectNumber(0, 1);
				if (answer == true)
						{
							cout << "Enter ID interval begining:" << endl;
							int min = GetCorrectNumber(0,1000);
							cout << "Enter ID interval endining:" << endl;
							int max = GetCorrectNumber(0,1000);
							EditPipeInterval(pipe, min, max);
						}
				else
						{
							EditGroup(pipe);
						}	
				
			break;
			}
			case 9:
			{
				int id;
				cout << "Enter id" << endl;
				cin >> id;
				if (pipe.find(id) == pipe.end())
				{
					cout << "ID not found" << endl;
				}
				else
				{
					remove(pipe, id);					
				}
				break;
			}
			case 10:
			{
				station.insert(make_pair(CStation::MaxID, CStation()));
				break;
			}
			case 11:
			{
				for (auto it = station.begin(); it != station.end(); it++)
					cout << it->second << endl;
				break;
			}
			case 12:
			{
				fstream fout;
				string filename;
				cout << "Save file name: ";
				cin >> filename;
				fout.open(filename + ".txt", fstream::out);
				if (fout.is_open())
				{
					for (auto it = station.begin(); it != station.end(); ++it)
					{
						fout << it->second << endl;
					}
				}
				fout.close();
				break;
			}
			case 13:
			{
				fstream fin;
				unordered_map<int, CStation> station2;
				string filename;
				cout << "Load file name: ";
				cin >> filename;
				fin.open(filename + ".txt", fstream::in);
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						CStation preset_station(fin);
						station2.insert(make_pair(preset_station.GetID(), preset_station));
					}
					fin.close();
					station = station2;
					CPipe::MID = FindMaxID(station);
				}
				else { cout << "error"; }
				break;
			}
			case 14:
			{
				string name;
				cout << "Name: " << endl;
				cin.ignore(10000, '\n');
				getline(cin, name);
				for (int i : FindByName(station, name))
				{
					cout << station[i] << endl;
				}
				cout << "Do you want edit this stations?" << endl;
				bool answer;
				answer = GetCorrectNumber(0, 1);
				if (answer == true)
				{
					for (int i : FindByName(station, name))
						station[i].EditStation();
				}
				else { break; }
			}
			case 15:
			{
				double percent;
				cout << "Percent of work workshops: " << endl;
				percent = GetCorrectNumber(0.0, 100.0);
				for (int i : FindByPercent(station, percent))
				{

					cout << station[i] << endl;
				}
				cout << "Do you want edit this stations?" << endl;
				bool answer;
				answer = GetCorrectNumber(0, 1);
				if (answer == true)
				{
					for (int i : FindByPercent(station, percent))
						station[i].EditStation();
				}
				else { break; }
			}
			case 16:
			{
				int id = GetCorrectNumber(1, 1000);
				station[id].EditStation();
				break;
			}
			case 17:
			{
				bool answer;
				cout << "1.Edit interval of pipes" << endl
					<< "0.Edit group of pipes" << endl;
				answer = GetCorrectNumber(0, 1);
				if (answer == true)
				{
					cout << "Enter ID interval begining:" << endl;
					int min = GetCorrectNumber(0, 1000);
					cout << "Enter ID interval endining:" << endl;
					int max = GetCorrectNumber(0, 1000);
					EditStationInterval(station, min, max);
				}
				else
				{
					EditGroupS(station);
				}

				break;
			}
			case 18:
			{
				int id;
				cout << "Enter id" << endl;
				cin >> id;
				if (station.find(id) == station.end())
				{
					cout << "ID not found" << endl;
				}
				else
				{
					remove(station, id);
				}
				break;
			}
			case 0:
			{
				return 0;
			}
		}
	}
}