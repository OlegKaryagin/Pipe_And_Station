#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CPipe.h"
#include "correctnumber.h"
#include "SStation.h"


using namespace std;


void Edit_Station_Menu()
{
	cout << "1. Edit the station name" << endl
		<< "2. Edit number of workshop" << endl
		<< "3. Edit number workshop in operation" << endl
		<< "4. Edit efficiency" << endl
		<< "0. Exit" << endl
		<< "Choose action:" << endl;
}





void Edit_Pipe_Menu()
{
	cout << "1. Edit length" << endl
		<< "2. Edit diametr" << endl
		<< "3. Edit status" << endl
		<< "0. Exit" << endl
		<< "Choose action:" << endl;
}




void PrintMenu()
{
	cout << "1. Create new pipe" << endl
		<< "2. Create new station" << endl
		<< "3. Print the pipe" << endl
		<< "4. Print the station" << endl
		<< "5. Edit the pipe" << endl
		<< "6. Edit the station" << endl
		<< "7. Save to file" << endl
		<< "8. Load from file" << endl
		<< "9. Find Pipe" << endl
		<< "10. Find Station" << endl
		<< "11. Delete pipe" << endl
		<< "12. Delete station" << endl
		<< "0. Exit" << endl
		<< "Choose action:" << endl;
}





CPipe& Select_Pipe(vector <CPipe>& pipe_group)
{
	cout << "Enter the index: " << endl;
	unsigned int index = GetcorrectNumber(1u, pipe_group.size());
	return pipe_group[index - 1];
}


SStation& Select_Station(vector <SStation>& station_group)
{
	cout << "Enter the index: " << endl;
	unsigned int index = GetcorrectNumber(1u, station_group.size() );
	return station_group[index-1];
}


int Delete_Pipe(vector <CPipe>& pipe_group)
{
	while (1)
	{
		cout << "1. Delete pipe" << endl
			<< "0. Back to menu" << endl;
		switch (GetcorrectNumber(0, 1))
		{
		case 1:
			{
				int index;
				cout << "Please, enter the pipe ID" << endl;
				index = GetcorrectNumber(1, 100000);
				pipe_group.erase(pipe_group.begin() + index - 1);
				for (index; index <= pipe_group.size() - 1; index++)
					pipe_group[index - 1] = pipe_group[index];
				break;
			}
		case 0:
			{
				return 0;
			}
		}

	}
}


int Delete_Station(vector <SStation>& station_group)
{
	while (1)
	{
		cout << "1. Delete station" << endl
			<< "0. Back to menu" << endl;
		switch (GetcorrectNumber(0, 1))
		{
		case 1:
		{
			int index;
			cout << "Please, enter the station ID" << endl;
			index = GetcorrectNumber(1, 100000);
			station_group.erase(station_group.begin() + index - 1);
			for (index; index <= station_group.size() - 1; index++)
				station_group[index - 1] = station_group[index];
			break;
		}
		case 0:
		{
			return 0;
		}
		}

	}
}


vector <int> Find_Pipe_Diametr(const vector<CPipe>& pipe_group, int diametr)
{
	vector <int> result;
	int index = 0;
	for (auto& CPipe : pipe_group)
	{
		if (CPipe.diametr == diametr)
			result.push_back(index);
		index++;
	}
	return result;

}


vector <int> Find_Pipe_Status(const vector<CPipe>& pipe_group, string status)
{
	vector <int> result;
	int index = 0;
	for (auto& CPipe : pipe_group)
	{
		if (CPipe.status == status)
			result.push_back(index);
		index++;
	}
	return result;

}


vector <int> Find_Station_Name(const vector<SStation>& station_group, string name)
{
	vector <int> result;
	int index = 0;
	for (auto& SStation : station_group)
	{
		if (SStation.name == name)
			result.push_back(index);
		index++;
	}
	return result;

}



vector <int> Find_Station_Not_Working_Workshop(const vector<SStation>& station_group, double percent)
{
	vector <int> result;
	int index = 0;
	for (auto& SStation : station_group)
	{
		double not_working_workshops;
		not_working_workshops = (static_cast<double>(SStation.number_of_workshops - SStation.workshops_in_operation)) / SStation.number_of_workshops;
		if (not_working_workshops >= percent/100)
			result.push_back(index);
		index++;
	}
	return result;
}


int Edit_Interval_Pipe(vector <CPipe>& pipe_group, int id_first_pipe, int id_last_pipe)
{
	while (1)
	{
		int i;
		Edit_Pipe_Menu();
		switch (GetcorrectNumber(0, 3))
		{
		case 1:
		{
			int  edit_length;
			cout << "Please, enter the pipe length (m, length = [1-2000000])" << endl;
			edit_length = GetcorrectNumber(1, 2000000);
			for (i = id_first_pipe; i <= id_last_pipe; i++)
				pipe_group[i].length = edit_length;
			cout << "Changes completed!" << endl;
			break;
		}
		case 2:
		{
			int  edit_diametr;
			cout << "Please, enter the pipe diametr (mm, diametr above 0)" << endl;
			edit_diametr = GetcorrectNumber(1, 10000);
			for (i = id_first_pipe; i <= id_last_pipe; i++)
				pipe_group[i].diametr = edit_diametr;
			cout << "Changes completed!" << endl;
			break;
		}
		case 3:
		{
			string edit_status;
			do
			{
				cout << "Please, enter the pipe status (work/repair)" << endl;
				cin >> edit_status;
			} while (edit_status != "work" & edit_status != "repair");
			for (i = id_first_pipe; i <= id_last_pipe; i++)
				pipe_group[i].status = edit_status;
			cout << "Changes completed!" << endl;
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Wrong action" << endl;
		}
		}
	}
	return 0;
}





int Find_Pipe( vector<CPipe>& pipe_group)
{
	while (1)
	{
		cout << "1. Find pipe by diametr" << endl
			<< "2. Find pipe by status" << endl
			<< "0. Back to main menu" << endl;
		switch (GetcorrectNumber(0, 2))
		{
		case 1:
			{
				int diametr;
				cout << "Please, enter the pipe diametr (mm, diametr above 0)" << endl;
				diametr = GetcorrectNumber(1, 10000);
				for (int i : Find_Pipe_Diametr(pipe_group, diametr))
					cout << pipe_group[i];
				Edit_Filtred_Pipe(Find_Pipe_Diametr(pipe_group,diametr),pipe_group);
				break;
			}
		case 2:
			{
				string status;
				do
				{
					cout << "Please, enter the pipe status (work/repair)" << endl;
					cin >> status;
				} while ((status != "work") & (status != "repair"));
				for (int i : Find_Pipe_Status(pipe_group, status))
					cout << pipe_group[i];
				Edit_Filtred_Pipe(Find_Pipe_Status(pipe_group, status), pipe_group);
				break;
			}
		case 0:
			{
				return 0;
			}
		default:
		{
			cout << "Wrong action" << endl;
		}
		}
	}
}


int Find_Station(vector<SStation>& station_group)
{
	while (1)
	{
		cout << "1. Find station by name" << endl
			<< "2. Find station by percent not working workshops" << endl
			<< "0. Back to main menu" << endl;
		switch (GetcorrectNumber(0, 2))
		{
		case 1:
		{
			string name;
			do
			{
				cin.clear();
				cin.ignore(1164, '\n');
				cout << "Please, enter the station name" << endl;
				getline(cin, name);
			} while (cin.fail());;
			for (int i : Find_Station_Name(station_group, name))
				cout << station_group[i];
			Edit_Filtred_Station(Find_Station_Name(station_group, name), station_group);
			break;
		}
		case 2:
		{
			double percent;
			cout << "Please, enter percent of Not working workshops:" << endl;
			percent = GetcorrectNumber(0, 100);
			for (int i : Find_Station_Not_Working_Workshop(station_group, percent))
				cout << station_group[i];
			Edit_Filtred_Station(Find_Station_Not_Working_Workshop(station_group, percent), station_group);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Wrong action" << endl;
		}
		}
	}
}







int main()
{
	unordered_map<int, SStation> station;
	unordered_map <int, CPipe> pipe;
	while (1)
	{
		PrintMenu();
		switch (GetcorrectNumber(0,12))
		{
		case 1:
			{
				pipe.insert(pair<int, CPipe>(CPipe::MaxID, CPipe()));
				break;
			}
		case 2:
			{	
			station.insert(pair<int, SStation>(SStation::MxID, SStation()));
				break;
			}
		case 3:
			{
				for (auto it = pipe.begin(); it != pipe.end(); ++it)
					cout << it-> second << endl;
				if (pipe.size() == 0)
					cout << "have not pipes";
				break;
			}
		case 4:
			{
				for (auto it = station.begin(); it != station.end(); ++it)
					cout << (*it), second << endl;
				if (station.size() == 0)
					cout << "have not station";
				break;
			}
		case 5:
		{
			Edit_Pipe(pipe_group);
			break;
		}
		case 6:
		{
			Edit_Station(station_group);
			break;
		}
		case 7:
		{	
			ofstream fout; 
			string file_name;
			cout << "Please, enterthe name of saving pipe file" << endl;
			cin >> file_name;
			file_name += ".txt";
			fout.open(file_name, ios::out);
			if (fout.is_open())
			{	
				fout << pipe_group.size() << endl;
				for (CPipe Preset_Pipe:pipe_group)
					Save_Pipe(fout, Preset_Pipe);
				fout.close();
			}
			else {
				cout << "Error opening file" << endl;
			}

			cout << "Please, enter the name of saving station file" << endl;
			cin >> file_name;
			file_name += ".txt";
			fout.open(file_name, ios::out);
			if (fout.is_open())
			{
				fout << station_group.size() << endl;
				for (SStation Preset_Station : station_group)
					Save_Station(fout, Preset_Station);
				fout.close();
			}
			else {
				cout << "Error opening file" << endl;
			}
			break;
		}
		case 8:
		{	
			ifstream fin;
			int count;
			string file_name;
			cout << "Please, enter the name of loading pipe file" << endl;
			cin >> file_name;
			file_name += ".txt";
				fin.open(file_name, ios::in);
				if (fin.is_open())
				{
					fin >> count;
					while (count--)
						pipe_group.push_back(Load_Pipe(fin));
					fin.close();
				}
				else {
					cout << "Error the opening file:" << file_name << endl;
				}

				cout << "Please, enter the name of loading station file" << endl;
				cin >> file_name;
				file_name += ".txt";
				fin.open(file_name, ios::in);
				if (fin.is_open())
				{
					fin >> count;
					while (count--)
						station_group.push_back(Load_Station(fin));
					fin.close();
				}
				else {
					cout << "Error the opening file:" << file_name << endl;
				}
			break;
		}
		case 9:
		{ 
			Find_Pipe(pipe_group);
			break;	
		}
		case 10:
		{
			Find_Station(station_group);
			break;
		}
		case 11:
		{
			Delete_Pipe(pipe_group);
			break;
		}
		case 12:
		{
			Delete_Station(station_group);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			{
				cout << "Wrong action"<< endl;
			}
		}
	}

	return 0;
}
