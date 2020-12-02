#include "CPipe.h"
#include <iostream>
#include <fstream>
#include "correctnumber.h"


using namespace std;


int CPipe::MaxID = 1;

CPipe::CPipe()
{
	this->id = MaxID++;
	this->length =GetcorrectNumber(1,1200);
	this->diametr = GetcorrectNumber(1,2520);
	this->status = false;
}



fstream& operator << (fstream& fout, const CPipe& work_pipe)
{
	fout << work_pipe.id << endl
		<< work_pipe.length << endl
		<< work_pipe.diametr << endl
		<< work_pipe.status << endl;
	return fout;
}



fstream& operator >> (fstream& fin, const CPipe& work_pipe)
{
	fin >> work_pipe.id;
	fin >> work_pipe.length;
	fin >> work_pipe.diametr;
	fin >> work-pipe.status;
	return fin;
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


void CPipe::Edit_Pipe()
{
	this->status = !status;
}



CPipe::CPipe(std::fstream& fin)
{
	fin >> this-> work_pipe.id;
	fin >> this-> work_pipe.length;
	fin >> this-> work_pipe.diametr;
	fin >> this-> work - pipe.status;
}