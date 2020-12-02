#pragma once
#include <string>

using namespace std;


class CPipe
{
	int id;
	int length;
	int diametr;
	public:
		static int MaxID;
		bool status;
	void Edit_Pipe();
		CPipe();
		CPipe(std::fstream& fin);


		friend std::fstream& operator >> (std::fstream& fin, CPipe& work_pipe);
		friend std::fstream& operator << (std::fstream& fout, const CPipe& work_pipe);
		friend std::ostream& operator << (std::ostream& out, const CPipe& work_pipe);
		friend std::istream& operator >> (std::istream& in, CPipe& work_pipe);
};

