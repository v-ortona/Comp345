#include <string>
using namespace std;

#ifndef CITY_H
#define CITY_H

//enum Colour { red, black, blue, yellow };

//Implementing the city as nodes
struct City
{
	int index;
	string name;
	bool infected;
	bool researchCenter;
	int infectionLevel;
	char colour;

	City() {                                         //default constructor
		name = string();
		infected = false;
		researchCenter = false;
		infectionLevel = 0;
	}


	City(int i) {                                        
		name = string();
		infected = false;
		researchCenter = false;
		infectionLevel = 0;
		index = i;
	}

	City(string cityName) {                          //constructor
		name = cityName;
	}

	string getName() {								// getter                     
		return this->name;
	}

	int accessCity() {
		return index;
	}

	void setColor(char colour) {
		this->colour = colour;
	}

	char getColor()
	{
		return this->colour;
	}

	void setResearchCenter(bool boolean) {
		this->researchCenter = boolean;
	}

	// the following methods are there for future use in the game
	void setInfection(bool infected) {
		this->infected = infected;
	}
	void incrementInfection() {
		infectionLevel++;
	}
	void decrementInfection() {
		infectionLevel--;
	}
	void setInfectionLevel(int l)
	{
		this->infectionLevel = l;
	}
	int getInfection()
	{
		return this->infectionLevel;
	}


};
#endif