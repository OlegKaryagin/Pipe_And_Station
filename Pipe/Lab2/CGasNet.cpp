#include "CGasNet.h"
#include <stack>
#include "CStation.h"
#include "Utils.h"
#include <numeric>
#include <set>
#include "CPipe.h"

CGasNet::CGasNet()
{

}

vector<int> FindByDiametr(const unordered_map<int, CPipe>& pipe, int param)
{
	vector <int> selected_pipes;
	selected_pipes.reserve(pipe.size());
	for (const auto& present_pipe : pipe)
	{
		if (present_pipe.second.GetDiametr() >= param)
			selected_pipes.push_back(present_pipe.first);
	}
	return selected_pipes;
}

vector<int> FindByStatus(const unordered_map<int, CPipe>& pipe, bool param)
{
	vector <int> selected_pipes;
	selected_pipes.reserve(pipe.size());
	for (const auto& present_pipe : pipe)
	{
		if (present_pipe.second.status == param)
			selected_pipes.push_back(present_pipe.first);
	}
	return selected_pipes;
}

vector<int> FindByName(const unordered_map<int, CStation>& station, string name)
{
	vector <int> selected_stations;
	selected_stations.reserve(station.size());
	for (const auto& present_station : station)
	{
		if (present_station.second.name == name)
			selected_stations.push_back(present_station.first);
	}
	return selected_stations;
}

vector<int> FindByPercent(const unordered_map<int, CStation>& station, double percent)
{
	double percent_workshop;
	vector <int> selected_stations;
	selected_stations.reserve(station.size());
	for (const auto& present_station : station)
	{
		percent_workshop = 100 * ((double)present_station.second.num_workshop_in_work / present_station.second.num_workshop);
		if (percent_workshop >= percent)
			selected_stations.push_back(present_station.first);
	}
	return selected_stations;
}

void CGasNet::EditStations()
{
	int id = GetCorrectNumber(1, 1000);
	stations[id].EditStation();
}



void EditStationInterval(unordered_map<int, CStation>& station, int min, int max)
{
	int work;
	cout << "Enter number of workshops in work" << endl;
	work = GetCorrectNumber(0, 100);
	if (min > max)
		swap(min, max);
	for (int i = min; i <= max; i++)
		if (work < station[i].num_workshop)
			station[i].num_workshop_in_work = work;
}

void EditStationGroup(const vector <int>& selects_stations, unordered_map<int, CStation>& station)
{
	int work;
	cout << "Enter number of workshops in work" << endl;
	work = GetCorrectNumber(0, 100);
	for (int i = 0; i < selects_stations.size(); i++)
	{
		if (work < station[selects_stations[i]].num_workshop)
			station[selects_stations[i]].num_workshop_in_work = work;
	}
}

void EditGroupS(unordered_map<int, CStation>& station)
{
	string help_str;
	vector <int> stations_for_edit;
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the stationss id: (by spaces)" << endl;
		getline(cin, help_str);
	} while (cin.fail());
	for (int i = 0; i < help_str.size(); i++)
		if (help_str[i] != ' ')
			stations_for_edit.push_back(help_str[i] - '0');
	EditStationGroup(stations_for_edit, station);
}

void CGasNet::EditStationsGroup()
{
	bool answer;
	cout << "1.Edit interval of pipes" << endl
		<< "0.Edit group of pipes" << endl;
	answer = GetCorrectNumber(0, 1);
	if (answer == true)
	{
		cout << "Enter ID interval begining:" << endl;
		int min = GetCorrectNumber(0, 1000);
		cout << "Enter ID interval endining:" << endl;
		int max = GetCorrectNumber(0, 1000);
		EditStationInterval(stations, min, max);
	}
	else
	{
		EditGroupS(stations);
	}
}





void EditPipeGroup(const vector <int>& selects_pipes, unordered_map<int, CPipe>& pipe)
{
	for (int i = 0; i < selects_pipes.size(); i++)
	{
		pipe[selects_pipes[i]].EditPipe();
	}
}

void EditGroup(unordered_map<int, CPipe>& pipe)
{
	string help_str;
	vector <int> pipes_for_edit;
	do
	{
		cin.clear();
		cin.ignore(1164, '\n');
		cout << "Please, enter the pipes id: (by spaces)" << endl;
		getline(cin, help_str);
	} while (cin.fail());
	for (int i = 0; i < help_str.size(); i++)
		if (help_str[i] != ' ')
			pipes_for_edit.push_back(help_str[i] - '0');
	EditPipeGroup(pipes_for_edit, pipe);
}

void EditPipeInterval(unordered_map<int, CPipe>& pipe, int min, int max)
{
	if (min > max)
		swap(min, max);
	for (int i = min; i <= max; i++)
		pipe[i].EditPipe();
}





void CGasNet::AddPipe()
{
	pipes.insert(make_pair(CPipe::MID, CPipe()));
}

void CGasNet::AddStation()
{
	stations.insert(make_pair(CStation::MaxID, CStation()));
}

void CGasNet::PrintPipes()
{
	for (auto it = pipes.begin(); it != pipes.end(); it++)
		cout << it->second << endl;
}

void CGasNet::PrintStations()
{
	for (auto it = stations.begin(); it != stations.end(); it++)
		cout << it->second << endl;
}

void CGasNet::SavePipes()
{
	fstream fout;
	string filename;
	cout << "Save file name: ";
	cin >> filename;
	fout.open(filename + ".txt", fstream::out);
	if (fout.is_open())
	{
		for (auto it = pipes.begin(); it != pipes.end(); ++it)
		{
			fout << it->second << endl;
		}
	}
	fout.close();
}

void CGasNet::SaveStations()
{
	fstream fout;
	string filename;
	cout << "Save file name: ";
	cin >> filename;
	fout.open(filename + ".txt", fstream::out);
	if (fout.is_open())
	{
		for (auto it = stations.begin(); it != stations.end(); ++it)
		{
			fout << it->second << endl;
		}
	}
	fout.close();
}

void CGasNet::FindPipeByDiametr()
{
	int diametr;
	cout << "Enter diametr" << endl;
	diametr = GetCorrectNumber(1, 10000);
	for (int i : FindByDiametr(pipes, diametr))
		cout << pipes[i] << endl;
}

void CGasNet::FindPipeByStatus()
{
	bool status;
	cout << "Enter status" << endl;
	cin >> status;
	for (int i : FindByStatus(pipes, status))
		cout << pipes[i] << endl;
}

void CGasNet::EditPipes()
{
	int id = GetCorrectNumber(1, 1000);
	pipes[id].EditPipe();
}

void CGasNet::EditPipesGroup()
{
	bool answer;
	cout << "1.Edit interval of pipes" << endl
		<< "0.Edit group of pipes" << endl;
	answer = GetCorrectNumber(0, 1);
	if (answer == true)
	{
		cout << "Enter ID interval begining:" << endl;
		int min = GetCorrectNumber(0, 1000);
		cout << "Enter ID interval endining:" << endl;
		int max = GetCorrectNumber(0, 1000);
		EditPipeInterval(pipes, min, max);
	}
	else
	{
		EditGroup(pipes);
	}
}

void CGasNet::FindStationsByName()
{
	string name;
	cout << "Name: " << endl;
	cin.ignore(10000, '\n');
	getline(cin, name);
	for (int i : FindByName(stations, name))
	{
		cout << stations[i] << endl;
	}
	cout << "Do you want edit this stations?" << endl;
	bool answer;
	answer = GetCorrectNumber(0, 1);
	if (answer == true)
	{
		for (int i : FindByName(stations, name))
			stations[i].EditStation();
	}
	
}

void CGasNet::FindStationsByPercent()
{
	double percent;
	cout << "Percent of work workshops: " << endl;
	percent = GetCorrectNumber(0.0, 100.0);
	for (int i : FindByPercent(stations, percent))
	{

		cout << stations[i] << endl;
	}
	cout << "Do you want edit this stations?" << endl;
	bool answer;
	answer = GetCorrectNumber(0, 1);
	if (answer == true)
	{
		for (int i : FindByPercent(stations, percent))
			stations[i].EditStation();
	}
}



void CGasNet::DeletePipe()
{
	int id;
	cout << "Enter id" << endl;
	cin >> id;
	if (pipes.find(id) == pipes.end())
	{
		cout << "ID not found" << endl;
	}
	else
	{
		remove(pipes, id);
	}
}

void CGasNet::DeleteStation()
{
	int id;
	cout << "Enter id" << endl;
	cin >> id;
	if (stations.find(id) == stations.end())
	{
		cout << "ID not found" << endl;
	}
	else
	{
		remove(stations, id);
	}
}

void CGasNet::LoadStation()
{
	fstream fin;
	unordered_map<int, CStation> station2;
	string filename;
	cout << "Load file name: ";
	cin >> filename;
	fin.open(filename + ".txt", fstream::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			CStation preset_station(fin);
			station2.insert(make_pair(preset_station.GetID(), preset_station));
		}
		fin.close();
		stations = station2;
		CStation::MaxID = FindMaxID(stations);
	}
	else { cout << "error"; }
}

void CGasNet::LoadPipe()
{
	fstream fin;
	unordered_map<int, CPipe> pipe2;
	string filename;
	cout << "Load file name: ";
	cin >> filename;
	fin.open(filename + ".txt", fstream::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			CPipe preset_pipe(fin);
			pipe2.insert(make_pair(preset_pipe.GetID(), preset_pipe));
		}
		fin.close();
		pipes = pipe2;
		CPipe::MID = FindMaxID(pipes);
	}
	else { cout << "error"; }
}

void CGasNet::ConnectStatiopn()
{
	int first;
	int second;
	int pipe_id;
	cout << "Enter the out station Id:" << endl;
	cin >> first;
	cout << "Enter the in station Id:" << endl;
	cin >> second;
	cout << "Enter the pipe id:" << endl;
	cin >> pipe_id;
	pipes[pipe_id].outStation = first;
	pipes[pipe_id].inStation = second;
}

bool CGasNet::CanBeUsed(const CPipe& pipe) const
{
	if (pipe.inStation != 0 && pipe.outStation != 0 && pipe.status)
		return true;
	else
		return false;
}

vector<vector<int>> CGasNet::GetEdgesAndVertexes(unordered_map<int, int>& indexVertexes, int& n)
{
	set<int> vertexes;
	for (const pair<int, CPipe>& p : pipes)
		if (p.second.inStation != 0)
		{
			vertexes.insert(p.second.outStation);
			vertexes.insert(p.second.inStation);
		}
	n = vertexes.size();
	unordered_map<int, int> invertIndexVertexes;
	int i = 0;
	for (const int& vertex : vertexes)
	{
		indexVertexes.insert(make_pair(i, vertex));
		invertIndexVertexes.insert(make_pair(vertex, i++));
	}
	vector<vector<int>> edges;
	edges.resize(n);
	for (const pair<int, CPipe>& p : pipes)
		if (p.second.inStation!=0)
			edges[invertIndexVertexes[p.second.outStation]].push_back(invertIndexVertexes[p.second.inStation]);
	return edges;
}

void topologicalSortUtil(int v, bool visited[], stack<int>& Stack, vector<vector<int>>& edges)
{
	visited[v] = true;

	vector<int>::iterator i;
	for (i = edges[v].begin(); i != edges[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack, edges);

	Stack.push(v);
}

bool dfs(int v, vector<char>& cl, vector<int>& p, int& cycle_st, const vector<vector<int>>& edges) {
	cl[v] = 1;
	for (size_t i = 0; i < edges[v].size(); ++i) {
		int to = edges[v][i];
		if (cl[to] == 0) {
			p[to] = v;
			if (dfs(to, cl, p, cycle_st, edges))
				return true;
		}
		else if (cl[to] == 1) {
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}

bool HasCycle(vector<vector<int>>& edges, int n)
{
	vector<char> cl;
	vector<int> p;
	int cycle_st;
	p.assign(n, -1);
	cl.assign(n, 0);
	cycle_st = -1;
	for (int i = 0; i < n; ++i)
		if (dfs(i, cl, p, cycle_st, edges))
			break;
	if (cycle_st == -1)
	{
		return false;
	}
	else
	{
		cout << "Attantion! Circle!\n";
		return true;
	}
}

void CGasNet::DeleteConnect()
{
	int pipe_id;
	cout << "Enter the in station Id:" << endl;
	cin >> pipe_id;
	pipes[pipe_id].outStation = 0;
	pipes[pipe_id].inStation = 0;
}

void CGasNet::TopologSort()
{
	unordered_map<int, int> indexVertexes;
	int n;
	vector<vector<int>> edges = GetEdgesAndVertexes(indexVertexes, n);
	if (HasCycle(edges, n) == false)
	{
		stack<int> Stack;

		bool* visited = new bool[n];
		for (int i = 0; i < n; i++)
			visited[i] = false;

		for (int i = 0; i < n; i++)
			if (visited[i] == false)
				topologicalSortUtil(i, visited, Stack, edges);

		while (Stack.empty() == false)
		{
			cout << "Station " << indexVertexes[Stack.top()] << " -> ";
			Stack.pop();
		}
	}
}

void CGasNet::ShowNetwork()
{
	for (const pair<int, CPipe>& p : pipes)
		if (p.second.inStation != 0)
			cout << "Station " << p.second.outStation << " -- Pipe " << p.first << " -> Station " << p.second.inStation << '\n';
}






