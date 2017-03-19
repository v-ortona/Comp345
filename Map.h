//#include "Player.h"
#include "City.h" 
#include <vector>

using namespace std;

#ifndef MAP_H
#define MAP_H
class Map
{
private:
	int size;
	bool** adjacencyMatrix; //represents the edges connecting cities
public:
	vector<City*> cities; //need to be public for Infectiondeck()

	bool blueCure;
	bool yellowCure;
	bool whiteCure;
	bool redCure;
	int researchStationNum;

	Map(int);
	~Map();

	City getCity(int i);

	City* accessCity(int i);

	//City* addCity(int i, string  name);

	vector<City*> getConnectedCities(int i);//pass index of city

	void addEdge(int i, int j);

	void showMap();

	void showCity(int i);

	void startGame();

	void saveMap();

	void loadMap(ifstream myfile);
};
#endif