#pragma once
#include <map>
#include <vector>
#include "CPipe.h"
#include "CStation.h"
using namespace std;

class CGasNet
{
	unordered_map<int, CPipe> pipes;
	unordered_map <int, CStation> stations;
	vector <int> nodes;
public:
	CGasNet();
	void AddPipe();
	void AddStation();
	void PrintPipes();
	void PrintStations();
	void SavePipes();
	void SaveStations();
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
	void LoadStation();
	void LoadPipe();
};