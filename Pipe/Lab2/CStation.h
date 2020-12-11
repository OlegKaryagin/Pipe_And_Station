#pragma once
#include <string>
#include <fstream>
#include <iostream>

class CStation
{
	int id;
public:
	int GetID() const;
	static int MaxID;
	std::string name;
	int num_workshop;
	int num_workshop_in_work;
	double efficiency;
	void EditStation();
	CStation();
	CStation(std::fstream& fin);;


	friend std::istream& operator >> (std::istream& in, CStation& station);
	friend std::ostream& operator << (std::ostream& out, const CStation& station);
	friend std::fstream& operator << (std::fstream& fout, const CStation& station);
	friend std::fstream& operator >> (std::fstream& fin, CStation& station);
};

