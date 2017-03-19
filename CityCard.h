#include "City.h"
#include "Card.h"
#include <string>
#include <vector>

using namespace std;

#ifndef CITYCARD_H
#define CITYCARD_H

class CityCard: public Card{
public:
	CityCard();
	CityCard(City* city);

	~CityCard();

	void playCard();

	int getID();

	string getCityName();

private:
	int id;
	City* city;

};

#endif