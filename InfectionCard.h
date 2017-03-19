//#pragma once
#include "City.h"
#include <string>
#include <vector>

using namespace std;

#ifndef INFECTIONCARD_H
#define INFECTIONCARD_H

class InfectionDeck; //forward declaration

class InfectionCard
{
private:
	int id;
public:
	City* city;

	InfectionCard();
	~InfectionCard();

	InfectionCard(City* city);

	int getID();
	string getCityName();

	void playCard(); //increment level based on infection marker

	void setLevel(int level); //set level manually

	void makeOutbreak();

};
#endif

