#include <iostream>


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


int main()
{
	Pipe Preset_Pipe = Create_New_Pipe();
	Print_Pipe(Preset_Pipe);
	return 0;
}
