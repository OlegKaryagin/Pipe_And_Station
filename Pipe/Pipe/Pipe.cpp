#include <iostream>
#include <fstream>


using namespace std;



struct Pipe
{
	short id;
	int length;
	int diametr;
	string status;
};



struct Station
{
	short id;
	string name;
	int number_of_workshops;
	int workshops_in_operation;
	int efficiency;
};



 Pipe Create_New_Pipe()
{
	Pipe New_Pipe;
	cout << "Please, enter the pipe id" << endl;
	cin >> New_Pipe.id;
	cout << "Please, enter the pipe length (mm)" << endl;
	cin >> New_Pipe.length;
	cout << "Please, enter the pipe diametr (mm)" << endl;
	cin >> New_Pipe.diametr;
	cout << "Please, enter the pipe status (work/repair)" << endl;
	cin >> New_Pipe.status;
	return New_Pipe;

}



void Print_Pipe(Pipe New_Pipe)
{
	cout << "Pipe ID:\t" << New_Pipe.id
		<< "\tPipe length:\t" << New_Pipe.length
		<< "\tPipe diametr:\t" << New_Pipe.diametr
		<< "\tPipe status:\t" << New_Pipe.status << endl;

}



void Edit_Pipe(Pipe& New_Pipe)
{
	New_Pipe.length -= 10;
}



void Save_Pipe(Pipe& New_Pipe)
{
	ofstream fout;
	fout.open("Save.txt", ios::out);
	fout << New_Pipe.id << endl << New_Pipe.length << endl << New_Pipe.diametr << endl << New_Pipe.status << endl;
	fout.close();
}



Pipe Load_Pipe()
{
	ifstream fin;
	fin.open("Save.txt", ios::in);
	Pipe New_Pipe;
	fin >> New_Pipe.id;
	fin >> New_Pipe.length;
	fin >> New_Pipe.diametr;
	fin >> New_Pipe.status;
	fin.close();
	return New_Pipe;
}

int main()
{
	Pipe Preset_Pipe = Create_New_Pipe();
	Print_Pipe(Preset_Pipe);
	Edit_Pipe(Preset_Pipe);
	Print_Pipe(Preset_Pipe);
	Save_Pipe(Preset_Pipe);
	Print_Pipe(Load_Pipe());
	return 0;
}
