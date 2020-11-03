#include "CPipe.h"
#include <iostream>
#include "correctnumber.h"


using namespace std;


int CPipe::MaxID = 1;

CPipe::CPipe()
{
	id = MaxID++;
	length = 0;
	diametr = 0;
	status = "Unknown";
}


bool correct(string test)
{
	return test == "work" || test == "repair";
}



ostream& operator << (ostream& out, const CPipe& work_pipe)
{
	out << "Pipe ID:\t" << work_pipe.id
		<< "\tPipe length:\t" << work_pipe.length
		<< "\tPipe diametr:\t" << work_pipe.diametr
		<< "\tPipe status:\t" << work_pipe.status << endl;
	return out;
}



istream& operator >> (istream& in, CPipe& work_pipe)
{
	cout << "Please, enter the pipe length (m, length = [1-2000000])" << endl;
	work_pipe.length = GetcorrectNumber(1, 2000000);
	cout << "Please, enter the pipe diametr (mm, diametr above 0)" << endl;
	work_pipe.diametr = GetcorrectNumber(1, 10000);
	do
	{
		cout << "Please, enter the pipe status (work/repair)" << endl;
		in >> work_pipe.status;
	} while (!correct(work_pipe.status));
	return in;
}
