#include <iostream>
#include <fstream>


using namespace std;



struct Pipe
{
	int id;
	int length;
	int diametr;
	string status;
};



struct Station
{
	int id;
	string name;
	int number_of_workshops;
	int workshops_in_operation;
	int efficiency;
};



bool correct(string test)
{
	return test == "work" || test == "repair";
}



bool above_0(int num)
{
	return num > 0;
}



Station Create_New_Station()
{
	Station New_station;
	do
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "Please, enter the station id (id above 0)" << endl;
		cin >> New_station.id;
	} while (cin.fail() || !above_0(New_station.id));
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the station name" << endl;
		cin >> New_station.name;
	} while (cin.fail());
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the number of workshop (Number above 0)" << endl;
		cin >>New_station.number_of_workshops;
	} while (cin.fail() || !above_0(New_station.number_of_workshops));
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the number workshop in operation (Number above 0)" << endl;
		cin >> New_station.workshops_in_operation;
	} while (cin.fail() || !above_0(New_station.workshops_in_operation));
	do
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "Please, enter the efficiency of station (0-100)" << endl;
		cin >> New_station.efficiency;
	} while (cin.fail() || New_station.efficiency <= 0);
	return New_station;
}



void Edit_Station(Station& New_station)
{
	New_station.number_of_workshops -= 1;
	New_station.number_of_workshops = above_0(New_station.number_of_workshops) ? New_station.number_of_workshops : 1;
}



void Save_Station(Station& New_Station)
{
	ofstream fout;
	fout.open("Save_Station.txt", ios::out);
	if (fout.is_open())
	{
		fout << New_Station.id << endl << New_Station.name << endl << New_Station.number_of_workshops << endl
			<< New_Station.workshops_in_operation << endl << New_Station.efficiency << endl;
		fout.close();
	}
	else {
		cout << "Error opening file" << endl;
	}
}



Station Load_Station()
{
	ifstream fin;
	Station New_Station;
	fin.open("Save_Station.txt", ios::in);
	if (fin.is_open())
	{
		fin >> New_Station.id;
		fin >> New_Station.name;
		fin >> New_Station.number_of_workshops;
		fin >> New_Station.workshops_in_operation;
		fin >> New_Station.efficiency;
		fin.close();
	}
	else {
		cout << "Error the opening file" << endl;
	}
	return New_Station;

}




 Pipe Create_New_Pipe()
{
	Pipe New_Pipe;
	do 
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please, enter the pipe id (id above 0)" << endl;
		cin >> New_Pipe.id;
	} while (cin.fail() || !above_0(New_Pipe.id));
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the pipe length (mm, length above 0)" << endl;
		cin >> New_Pipe.length;
	} while (cin.fail() || !above_0(New_Pipe.length));
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the pipe diametr (mm, diametr above 0)" << endl;
		cin >> New_Pipe.diametr;
	} while (cin.fail() || !above_0(New_Pipe.diametr));
	do
	{
		cout << "Please, enter the pipe status (work/repair)" << endl;
		cin >> New_Pipe.status;
	} while (!correct(New_Pipe.status));
	return New_Pipe;

}



void Print(Pipe New_Pipe, Station New_Station)
{
	cout << "Pipe ID:\t" << New_Pipe.id
		<< "\tPipe length:\t" << New_Pipe.length
		<< "\tPipe diametr:\t" << New_Pipe.diametr
		<< "\tPipe status:\t" << New_Pipe.status << endl;
	cout << "Station ID:\t" << New_Station.id
		<< "\tStation name:\t" << New_Station.name
		<< "\tNumber of workshop:\t" << New_Station.number_of_workshops
		<< "\tWorkshops in operation:\t" << New_Station.workshops_in_operation
		<< "\tStation efficiency:\t" << New_Station.efficiency << endl;

}



void Edit_Pipe(Pipe& New_Pipe)
{
	New_Pipe.length -= 10;
	New_Pipe.length = above_0(New_Pipe.length) ? New_Pipe.length : 1;
}



void Save_Pipe(Pipe& New_Pipe)
{
	ofstream fout;
	fout.open("Save.txt", ios::out);
	if (fout.is_open())
	{
		fout << New_Pipe.id << endl << New_Pipe.length << endl << New_Pipe.diametr << endl << New_Pipe.status << endl;
		fout.close();
	}
	else {
		cout << "Error opening file" << endl;
	}
}



Pipe Load_Pipe()
{
	ifstream fin;
	Pipe New_Pipe;
	fin.open("Save.txt", ios::in);
	if (fin.is_open())
	{
		fin >> New_Pipe.id;
		fin >> New_Pipe.length;
		fin >> New_Pipe.diametr;
		fin >> New_Pipe.status;
		fin.close();
	}
	else {
		cout << "Error the opening file" << endl;
	}
	return New_Pipe;

}



void PrintMenu()
{
	cout << "1. Create new pipe" << endl
		<< "2. Create new station" << endl
		<< "3. Print the object" << endl
		<< "4. Edit the pipe" << endl
		<< "5. Edit the station" << endl
		<< "6. Save to file" << endl
		<< "7. Load from file" << endl
		<< "0. Exit" << endl;
}

int main()
{
	Station Preset_Station;
	Pipe Preset_Pipe;
	while (1)
	{
		PrintMenu();
		int i = 0;
		do
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> i;
		} while (cin.fail());
		switch (i)
		{
		case 1:
			{
				Preset_Pipe= Create_New_Pipe();
				break;
			}
		case 2:
			{
				Preset_Station = Create_New_Station();
				break;
			}
		case 3:
			{
				Print(Preset_Pipe,Preset_Station);
				break;
			}
		case 4:
		{
			Edit_Pipe(Preset_Pipe);
			break;
		}
		case 5:
		{
			Edit_Station(Preset_Station);
			break;
		}
		case 6:
		{
			Save_Pipe(Preset_Pipe);
			Save_Station(Preset_Station);
			break;
		}
		case 7:
		{
			Preset_Pipe=Load_Pipe();
			Preset_Station = Load_Station();
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
	Print(Preset_Pipe,Preset_Station);
	
	Print(Preset_Pipe,Preset_Station);

	return 0;
}
