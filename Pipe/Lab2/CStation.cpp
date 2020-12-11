#include "CStation.h"
#include "Utils.h"
using namespace std;

int CStation::GetID() const
{
    return id;
}

istream& operator >> (istream& in, CStation& station)
{
	cout << "Name: " << endl;
	cin.ignore(10000, '\n');
	getline(cin, station.name);
	cout << "Number of workshop:" << endl;
	station.num_workshop = GetCorrectNumber(1,100);
	cout << "Number of workshop in work:" << endl;
	station.num_workshop_in_work = GetCorrectNumber(1,station.num_workshop);
	cout << "Efficiency:" << endl;
	station.efficiency = GetCorrectNumber(1.0,100.0);
	return in;
}

ostream& operator << (ostream& out, const CStation& station)
{
	out << "CStation" << "    ID: " << station.id
		<< "    Name: " << station.name << "    (workshop in work/all)  " << station.num_workshop_in_work
		<< "/" << station.num_workshop << "    Efficiency= " << station.efficiency;
	return out;
}

fstream& operator<<(std::fstream& fout, const CStation& station)
{
	fout << station.id << endl << station.name << endl << station.num_workshop << endl << station.num_workshop_in_work << endl << station.efficiency;
	return fout;
}

fstream& operator>>(std::fstream& fin, CStation& station)
{
	fin >> station.id >> station.name >> station.num_workshop >> station.num_workshop_in_work >> station.efficiency;
	return fin;
}


int CStation::MaxID = 0;

void CStation::EditStation()
{
    cout << "Number of workshop in work:" << endl;
    this->num_workshop_in_work = GetCorrectNumber(1,this->num_workshop);
}

CStation::CStation()
{
    this->id = ++MaxID;
    cout << "Name:" << endl;
    cin.ignore(10000, '\n');
    getline(cin, this->name);
    cout << "Number of workshop:" << endl;
    this->num_workshop = GetCorrectNumber(1, 100);
    cout << "Number workshop in work:" << endl;
    this->num_workshop_in_work = GetCorrectNumber(1, this->num_workshop);
    cout << "Efficiency:" << endl;
    this->efficiency = GetCorrectNumber(1.0, 100.0);
}

CStation::CStation(std::fstream& fin)
{
	fin >> this->id;
	fin.ignore(10000, '\n');
	getline(fin, this->name);
	fin >> this->num_workshop >> this->num_workshop_in_work >> this->efficiency;
}
