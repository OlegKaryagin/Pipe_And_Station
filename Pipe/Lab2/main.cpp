#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Utils.h"
#include "CPipe.h"
#include "CStation.h"
#include "CGasNet.h"

using namespace std;






void MainMenu()
{
	cout << "1.New pipe." << endl
		<< "2. Print pipe." << endl
		<< "3. Save pipe." << endl
		<< "4. Load pipe." << endl
		<< "5.Find pipe by diametr." << endl
		<< "6. Find pipe by status." << endl
		<< "7. Edit pipe." << endl
		<< "8. Edit pipe group." << endl
		<< "9. Delete pipe." << endl
		<< "10.New station." << endl
		<< "11. Print station." << endl
		<< "12. Save station." << endl
		<< "13. Load station." << endl
		<< "14.Find station by name." << endl
		<< "15. Find station by percent." << endl
		<< "16. Edit station." << endl
		<< "17. Edit station group." << endl
		<< "18. Delete station." << endl
		<< "0. Exit." << endl;
}

int main()
{
	CGasNet gasnet;
	while (1)
	{
		MainMenu();
		switch (GetCorrectNumber(0, 20))
		{
			case 1:
			{
				gasnet.AddPipe();
				break;
			}
			case 2:
			{
				gasnet.PrintPipes();
				break;
			}
			case 3:
			{
				gasnet.SavePipes();
				break;
			}
			case 4:
			{
				gasnet.LoadPipe();
				break;
			}
			case 5:
			{
				gasnet.FindPipeByDiametr();
				break;
			}
			case 6:
			{
				gasnet.FindPipeByStatus();
				break;
			}
			case 7:
			{
				gasnet.EditPipes();
				break;
			}
			case 8:
			{
				gasnet.EditPipesGroup();
				break;
			}
			case 9:
			{
				gasnet.DeletePipe();
				break;
			}
			case 10:
			{
				gasnet.AddStation();
				break;
			}
			case 11:
			{
				gasnet.PrintStations();
				break;
			}
			case 12:
			{
				gasnet.SaveStations();
				break;
			}
			case 13:
			{
				gasnet.LoadStation();
				break;
			}
			case 14:
			{
				gasnet.FindStationsByName();
				break;
			}
			case 15:
			{
				gasnet.FindStationsByPercent();
				break;
			}
			case 16:
			{
				gasnet.EditStations();
				break;
			}
			case 17:
			{			
				gasnet.EditStationsGroup();
				break;
			}
			case 18:
			{
				gasnet.DeleteStation();
				break;
			}
			case 19:
			{
				gasnet.ConnectStatiopn();
				break;
			}
			case 20:
			{
				gasnet.FillMatrSmezh();
				break;
			}
			case 0:
			{
				return 0;
			}
		}
	}
}