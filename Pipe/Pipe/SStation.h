#pragma once
#include <string>

using namespace std;

class SStation
{
	int InD;
public:
	static int MxID;
	string name;
	int number_of_workshops;
	int workshops_in_operation;
	int efficiency;


	SStation();


	friend std::ostream& operator << (std::ostream& out, const SStation& work_station);
	friend std::istream& operator >> (std::istream& in, SStation& work_station);
};










