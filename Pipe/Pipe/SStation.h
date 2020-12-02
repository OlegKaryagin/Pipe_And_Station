#pragma once
#include <string>

using namespace std;

class SStation
{
	int InD;
	string name;
public:
	static int MxID;
	int number_of_workshops;
	int workshops_in_operation;
	int efficiency;

	void Edit_Station();
	SStation();
	SStation(std::fstream& fin);

	friend std::fstream& operator >> (std::fstream& fin, SStation& work_station);
	friend std::fstream& operator << (std::fstream& fout, const SStation& work_station);
	friend std::ostream& operator << (std::ostream& out, const SStation& work_station);
	friend std::istream& operator >> (std::istream& in, SStation& work_station);
};










