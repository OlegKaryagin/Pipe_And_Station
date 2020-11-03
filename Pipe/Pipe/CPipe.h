#pragma once
#include <string>

using namespace std;


class CPipe
{
	int id;
	public:
		static int MaxID;
		int length;
		int diametr;
		string status;

		CPipe();


		friend std::ostream& operator << (std::ostream& out, const CPipe& work_pipe);
		friend std::istream& operator >> (std::istream& in, CPipe& work_pipe);
};

