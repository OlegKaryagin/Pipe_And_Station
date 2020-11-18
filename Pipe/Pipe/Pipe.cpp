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




int Edit_One_Station(SStation& work_station)
{	
	while (1)
	{
		Edit_Station_Menu();
		switch (GetcorrectNumber(0, 4))
		{
		case 1:
		{
			do
			{
				cin.clear();
				cin.ignore(1164, '\n');
				cout << "Please, enter the station name" << endl;
				getline(cin, work_station.name);
			} while (cin.fail());
			break;
		}
		case 2:
		{
			cout << "Please, enter the number of workshop (Number [1-100])" << endl;
			work_station.number_of_workshops = GetcorrectNumber(1, 100);
			break;
		}
		case 3:
		{
			do
			{
				cin.clear();
				cin.ignore(1164, '\n');
				cout << "Please, enter the number workshop in operation (Number above 0)" << endl;
				cin >> work_station.workshops_in_operation;
			} while (cin.fail() || (work_station.workshops_in_operation) <= 0 || work_station.workshops_in_operation > work_station.number_of_workshops);
			break;
		}
		case 4:
		{
			cout << "Please, enter the efficiency of station (0-100)" << endl;
			work_station.efficiency = GetcorrectNumber(0, 100);
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



void Save_Station(ofstream& fout, SStation& New_Station)
{
		fout << New_Station.name << endl << New_Station.number_of_workshops << endl
			<< New_Station.workshops_in_operation << endl << New_Station.efficiency << endl;
}



SStation Load_Station(ifstream& fin)
{
		SStation New_Station;
		fin.get();
		getline(fin, New_Station.name);
		fin >> New_Station.number_of_workshops;
		fin >> New_Station.workshops_in_operation;
		fin >> New_Station.efficiency;
	return New_Station;

}


void Edit_Pipe_Menu()
{
	cout << "1. Edit length" << endl
		<< "2. Edit diametr" << endl
		<< "3. Edit status" << endl
		<< "0. Exit" << endl
		<< "Choose action:" << endl;
}

int Edit_One_Pipe(CPipe& work_pipe)
{
	while (1)
	{
		Edit_Pipe_Menu();
		switch (GetcorrectNumber(0, 3))
		{
			case 1:
				{
					cout << "Please, enter the pipe length (m, length = [1-2000000])" << endl;
					work_pipe.length = GetcorrectNumber(1, 2000000);
					break;
				}
			case 2:
				{
					cout << "Please, enter the pipe diametr (mm, diametr above 0)" << endl;
					work_pipe.diametr = GetcorrectNumber(1, 10000);
					break;
				}
			case 3:
				{
					do
					{
						cout << "Please, enter the pipe status (work/repair)" << endl;
						cin >> work_pipe.status;
					} while ((work_pipe.status) == "work" || (work_pipe.status) == "repair");
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



void Save_Pipe(ofstream& fout, CPipe& New_Pipe)
{
	
		fout  << New_Pipe.length << endl << New_Pipe.diametr << endl << New_Pipe.status << endl;
		
}



CPipe Load_Pipe(ifstream& fin)
{
	CPipe New_Pipe;

		fin >> New_Pipe.length;
		fin >> New_Pipe.diametr;
		fin >> New_Pipe.status;
	return New_Pipe;

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


int Edit_Filtred_Pipe(vector <int> Find_Pipe, vector <CPipe>& pipe_group)
{
	while (1)
	{
		cout << "Do you want to change these pipes?" << endl
			<< "1. Yes." << endl
			<< "0. I'm just watching" << endl;
		switch (GetcorrectNumber(0, 1))
		{
		case 1:
		{
			Edit_Interval_Pipe(pipe_group, Find_Pipe[0], Find_Pipe[Find_Pipe.size() - 1]);
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
}


int Edit_Interval_Station(vector <SStation>& station_group, int id_first_station, int id_last_station)
{
	while (1)
	{
		int i;
		Edit_Station_Menu();
		switch (GetcorrectNumber(0, 4))
		{
		case 1:
		{
			for (i = id_first_station; i <= id_last_station; i++)
			{
				do
				{
					cin.clear();
					cin.ignore(1164, '\n');
					cout << "Please, enter the station name" << endl;
					getline(cin, station_group[i].name);
				} while (cin.fail());
			}
			break;
		}
		case 2:
		{
			int edit_number_of_workshops;
			cout << "Please, enter the number of workshop (Number [1-100])" << endl;
			edit_number_of_workshops = GetcorrectNumber(1, 100);
			for (i = id_first_station; i <= id_last_station; i++)
				station_group[i].number_of_workshops = edit_number_of_workshops;
			break;
		}
		case 3:
		{
			int edit_workshops_in_operation;
			do
			{
				cin.clear();
				cin.ignore(1164, '\n');
				cout << "Please, enter the number workshop in operation (Number above 0)" << endl;
				cin >> edit_workshops_in_operation;
			} while (cin.fail() || (edit_workshops_in_operation) <= 0);
			for (i = id_first_station; i <= id_last_station; i++)
			{
				if (edit_workshops_in_operation <= station_group[i].number_of_workshops)
				{
					station_group[i].workshops_in_operation = edit_workshops_in_operation;
				}
			}
			break;
		}
		case 4:
		{
			int edit_efficiency;
			cout << "Please, enter the efficiency of station (0-100)" << endl;
			edit_efficiency = GetcorrectNumber(0, 100);
			for (i = id_first_station; i <= id_last_station; i++)
				station_group[i].efficiency = edit_efficiency;
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


int Edit_Filtred_Station(vector <int> Find_Station, vector <SStation>& station_group)
{
	while (1)
	{
		cout << "Do you want to change these stations?" << endl
			<< "1. Yes." << endl
			<< "0. I'm just watching" << endl;
		switch (GetcorrectNumber(0, 1))
		{
		case 1:
		{
			Edit_Interval_Station(station_group, Find_Station[0], Find_Station[Find_Station.size()-1]);
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
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





int Edit_Pipe(vector <CPipe>& pipe_group)
{
	while (1)
	{
		cout << "1. Edit one pipe" << endl
			<< "2. Edit pipes on interval" << endl
			<< "3. Edit all pipes" << endl
			<< "0. Back to main menu" << endl;
		switch (GetcorrectNumber(0, 3))
		{
			case 1:
				{
					Edit_One_Pipe(Select_Pipe(pipe_group));
					break;
				}
			case 2:
				{
					int id_first_pipe, id_last_pipe;
					cout << "Enter id first pipe and id last pipe in interval" << endl;
					id_first_pipe = GetcorrectNumber(1,1000);
					id_last_pipe = GetcorrectNumber(1, 1000);
					Edit_Interval_Pipe(pipe_group, id_first_pipe-1, id_last_pipe-1);
					break;
				}
			case 3:
			{
				Edit_Interval_Pipe(pipe_group, 0, pipe_group.size()-1);
				break;
			}
			case 0:
			{
				return 0;
			}
		}
	}
}





int Edit_Station(vector <SStation>& station_group)
{
	while (1)
	{
		cout << "1. Edit one station" << endl
			<< "2. Edit stations on interval" << endl
			<< "3. Edit all stations" << endl
			<< "0. Back to main menu" << endl;
		switch (GetcorrectNumber(0, 3))
		{
		case 1:
		{
			Edit_One_Station(Select_Station(station_group));
			break;
		}
		case 2:
		{
			int id_first_station, id_last_station;
			cout << "Enter id first station and id last station in interval" << endl;
			id_first_station = GetcorrectNumber(1, 1000);
			id_last_station = GetcorrectNumber(1, 1000);
			Edit_Interval_Station(station_group, id_first_station - 1, id_last_station - 1);
			break;
		}
		case 3:
		{
			Edit_Interval_Station(station_group, 0, station_group.size() - 1);
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
}





int main()
{
	vector <SStation> station_group;
	vector <CPipe> pipe_group;
	while (1)
	{
		PrintMenu();
		switch (GetcorrectNumber(0,12))
		{
		case 1:
			{
				CPipe Preset_Pipe;
				cin >> Preset_Pipe;
				pipe_group.push_back(Preset_Pipe);
				break;
			}
		case 2:
			{	
				SStation Preset_Station;
				cin >> Preset_Station;
				station_group.push_back(Preset_Station);
				break;
			}
		case 3:
			{
				for (auto& Select_Pipe: pipe_group)
					cout << Select_Pipe << endl;
				break;
			}
		case 4:
			{
				for (auto& Select_Station: station_group)
					cout << Select_Station << endl;
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
