#include "CPipe.h"
#include "Utils.h"
#include <fstream>

using namespace std;







CPipe::CPipe(std::fstream& fin)
{
	fin >> this->id >> this->length >> this->diametr >> this->status >> this->inStation >> this->outStation;
}

void CPipe::EditPipe()
{
	this->status = !status;
}




fstream& operator << (fstream& fout, const CPipe& work_pipe)
{
	fout << work_pipe.id << endl
		<< work_pipe.length << endl
		<< work_pipe.diametr << endl
		<< work_pipe.status << endl
		<< work_pipe.inStation << endl
		<< work_pipe.outStation << endl;
	return fout;
}

fstream& operator >> (fstream& fin, CPipe& work_pipe)
{
	fin >> work_pipe.id >> work_pipe.length >> work_pipe.diametr >> work_pipe.status >> work_pipe.inStation >> work_pipe.outStation;
	return fin;
}

istream& operator >> (istream& in, CPipe& work_pipe)
{
	work_pipe.length = GetCorrectNumber(1, 1200);
	work_pipe.diametr = GetCorrectNumber(1, 2520);
	work_pipe.status = true;
	return in;
}

ostream& operator << (ostream& out, const CPipe& work_pipe)
{
	out << "Pipe ID: " << work_pipe.id << endl
		<< "Pipe length: " << work_pipe.length << endl
		<< "Pipe diametr: " << work_pipe.diametr << endl
		<< (work_pipe.status ? "Work" : "Repair") << endl;
	return out;
}


int CPipe::MID = 0;

CPipe::CPipe()
{
	this->id = ++MID;
	cout << "Length:" << endl;
	this->length = GetCorrectNumber(1, 1200);
	cout << "Diametr" << endl;
	this->diametr = GetCorrectNumber(1, 2520);
	this->status = true;
}

int CPipe::GetID() const
{
	return id;
}

int CPipe::GetLength() const
{
	return length;
}

int CPipe::GetDiametr() const
{
	return diametr;
}



