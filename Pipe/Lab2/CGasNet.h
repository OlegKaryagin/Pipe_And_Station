#pragma once
#include <map>
#include <vector>
#include "CPipe.h"
#include "CStation.h"
#include <stack>
using namespace std;

class CGasNet
{
	unordered_map<int, CPipe> pipes;
	unordered_map <int, CStation> stations;
	vector<vector<int>> GetEdgesAndVertexes(unordered_map<int, int>& indexVertexes, int& n);

public:
	CGasNet();
	void AddPipe();
	void AddStation();
	void PrintPipes();
	void PrintStations();
	void Save();
	void FindPipeByDiametr();
	void FindPipeByStatus();
	void EditPipes();
	void EditPipesGroup();
	void FindStationsByName();
	void FindStationsByPercent();
	void EditStations();
	void EditStationsGroup();
	void DeletePipe();
	void DeleteStation();
	void Load();
	void ConnectStatiopn();
	bool CanBeUsed(const CPipe& pipe) const;
	void TopologSort();
	void DeleteConnect();
	void ShowNetwork();
	
	
};