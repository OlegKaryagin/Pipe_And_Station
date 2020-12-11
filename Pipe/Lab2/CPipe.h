#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class CPipe
{
	
	int id;
	int length;
	int diametr;

public:
	int GetID() const;
	int GetLength() const;
	int GetDiametr() const;
	static int MID;
	bool status;

	CPipe();
	CPipe(std::fstream& fin);
	void EditPipe();


	friend std::fstream& operator >> (std::fstream& fin, CPipe& work_pipe);
	friend std::fstream& operator << (std::fstream& fout, const CPipe& work_pipe);
	friend std::ostream& operator << (std::ostream& out, const CPipe& work_pipe);
	friend std::istream& operator >> (std::istream& in, CPipe& work_pipe);
};

