#include "SStation.h"
#include <iostream>
#include "correctnumber.h"





using namespace std;

int SStation::MxID = 1;


SStation::SStation()
{
	InD = MxID++;
	name = "Unknown";
	number_of_workshops = 0;
	workshops_in_operation = 0;
	efficiency = 0;
}


ostream& operator << (ostream& out, const SStation& work_station)
{
	out << "Station ID:\t" << work_station.InD
		<< "\tStation name:\t" << work_station.name
		<< "\tNumber of workshop:\t" << work_station.number_of_workshops
		<< "\tWorkshops in operation:\t" << work_station.workshops_in_operation
		<< "\tStation efficiency:\t" << work_station.efficiency << endl;
	return out;
}


istream& operator >> (istream& in, SStation& work_station)
{
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the station name" << endl;
		getline(in, work_station.name);
	} while (cin.fail());
	cout << "Please, enter the number of workshop (Number [1-100])" << endl;
	work_station.number_of_workshops = GetcorrectNumber(1, 100);
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the number workshop in operation (Number above 0)" << endl;
		in >> work_station.workshops_in_operation;
	} while (cin.fail() || (work_station.workshops_in_operation)<=0 || work_station.workshops_in_operation > work_station.number_of_workshops);
	cout << "Please, enter the efficiency of station (0-100)" << endl;
	work_station.efficiency = GetcorrectNumber(0, 100);
	return in;
}