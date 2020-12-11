#pragma once
#include <iostream>
#include <unordered_map>


using namespace std;

template <typename T>

T GetCorrectNumber(T min, T max)
{
	T x;
	while ((cin >> x).fail() || x<min || x>max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Input error!" << endl;
	}
	return x;
}

template <typename T>

void remove(unordered_map <int, T>& t, int id)
{
	t.erase(id);
}

template <typename T>

int FindMaxID(const unordered_map<int, T>& t)
{
	int MID = -100;
	for (const auto& i : t)
		if (i.second.GetID()> MID)
			MID = i.second.GetID();
	return MID;
}


