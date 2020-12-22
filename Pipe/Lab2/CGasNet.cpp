#include "CGasNet.h"
#include <stack>
#include "CStation.h"
#include "Utils.h"

CGasNet::CGasNet()
{

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

void CGasNet::EditStations()
{
	int id = GetCorrectNumber(1, 1000);
	stations[id].EditStation();
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

void EditStationGroup(const vector <int>& selects_stations, unordered_map<int, CStation>& station)
{
	int work;
	cout << "Enter number of workshops in work" << endl;
	work = GetCorrectNumber(0, 100);
	for (int i = 0; i < selects_stations.size(); i++)
	{
		if (work < station[selects_stations[i]].num_workshop)
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

void CGasNet::EditStationsGroup()
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
		EditStationInterval(stations, min, max);
	}
	else
	{
		EditGroupS(stations);
	}
}





void EditPipeGroup(const vector <int>& selects_pipes, unordered_map<int, CPipe>& pipe)
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





void CGasNet::AddPipe()
{
	pipes.insert(make_pair(CPipe::MID, CPipe()));
}

void CGasNet::AddStation()
{
	stations.insert(make_pair(CStation::MaxID, CStation()));
}

void CGasNet::PrintPipes()
{
	for (auto it = pipes.begin(); it != pipes.end(); it++)
		cout << it->second << endl;
}

void CGasNet::PrintStations()
{
	for (auto it = stations.begin(); it != stations.end(); it++)
		cout << it->second << endl;
}

void CGasNet::SavePipes()
{
	fstream fout;
	string filename;
	cout << "Save file name: ";
	cin >> filename;
	fout.open(filename + ".txt", fstream::out);
	if (fout.is_open())
	{
		for (auto it = pipes.begin(); it != pipes.end(); ++it)
		{
			fout << it->second << endl;
		}
	}
	fout.close();
}

void CGasNet::SaveStations()
{
	fstream fout;
	string filename;
	cout << "Save file name: ";
	cin >> filename;
	fout.open(filename + ".txt", fstream::out);
	if (fout.is_open())
	{
		for (auto it = stations.begin(); it != stations.end(); ++it)
		{
			fout << it->second << endl;
		}
	}
	fout.close();
}

void CGasNet::FindPipeByDiametr()
{
	int diametr;
	cout << "Enter diametr" << endl;
	diametr = GetCorrectNumber(1, 10000);
	for (int i : FindByDiametr(pipes, diametr))
		cout << pipes[i] << endl;
}

void CGasNet::FindPipeByStatus()
{
	bool status;
	cout << "Enter status" << endl;
	cin >> status;
	for (int i : FindByStatus(pipes, status))
		cout << pipes[i] << endl;
}

void CGasNet::EditPipes()
{
	int id = GetCorrectNumber(1, 1000);
	pipes[id].EditPipe();
}

void CGasNet::EditPipesGroup()
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
		EditPipeInterval(pipes, min, max);
	}
	else
	{
		EditGroup(pipes);
	}
}

void CGasNet::FindStationsByName()
{
	string name;
	cout << "Name: " << endl;
	cin.ignore(10000, '\n');
	getline(cin, name);
	for (int i : FindByName(stations, name))
	{
		cout << stations[i] << endl;
	}
	cout << "Do you want edit this stations?" << endl;
	bool answer;
	answer = GetCorrectNumber(0, 1);
	if (answer == true)
	{
		for (int i : FindByName(stations, name))
			stations[i].EditStation();
	}
	
}

void CGasNet::FindStationsByPercent()
{
	double percent;
	cout << "Percent of work workshops: " << endl;
	percent = GetCorrectNumber(0.0, 100.0);
	for (int i : FindByPercent(stations, percent))
	{

		cout << stations[i] << endl;
	}
	cout << "Do you want edit this stations?" << endl;
	bool answer;
	answer = GetCorrectNumber(0, 1);
	if (answer == true)
	{
		for (int i : FindByPercent(stations, percent))
			stations[i].EditStation();
	}
}



void CGasNet::DeletePipe()
{
	int id;
	cout << "Enter id" << endl;
	cin >> id;
	if (pipes.find(id) == pipes.end())
	{
		cout << "ID not found" << endl;
	}
	else
	{
		remove(pipes, id);
	}
}

void CGasNet::DeleteStation()
{
	int id;
	cout << "Enter id" << endl;
	cin >> id;
	if (stations.find(id) == stations.end())
	{
		cout << "ID not found" << endl;
	}
	else
	{
		remove(stations, id);
	}
}

void CGasNet::LoadStation()
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
		stations = station2;
		CPipe::MID = FindMaxID(stations);
	}
	else { cout << "error"; }
}

void CGasNet::LoadPipe()
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
		pipes = pipe2;
		CPipe::MID = FindMaxID(pipes);
	}
	else { cout << "error"; }
}

void CGasNet::ConnectStatiopn()
{
	int first;
	int second;
	int pipe_id;
	cout << "Enter the out station Id:" << endl;
	cin >> first;
	cout << "Enter the in station Id:" << endl;
	cin >> second;
	cout << "Enter the pipe id:" << endl;
	cin >> pipe_id;
	pipes[pipe_id].outStation = first;
	pipes[pipe_id].inStation = second;
}

bool CGasNet::Proverka(int a, int b)
{
	for (auto t : pipes)
	{
		if (pipes[t.first].outStation == a)
			if (pipes[t.first].inStation == b)
				return true;
			else
				return false;
		else
			false;
	}

}

void CGasNet::FillMatrSmezh()
{
	for (auto i : stations)
	{
		for (auto j : stations)
		{
			if (Proverka(i.first, j.first))
				strok.push_back(1);
			else
				strok.push_back(0);
		}
		matrSmezh.push_back(strok);
	}
}



