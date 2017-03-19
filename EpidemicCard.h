#pragma once
#include "Card.h"
#include <string>
#include <vector>
#include "InfectionDeck.h"
using namespace std;

class EpidemicCard : public Card {
public:
	EpidemicCard();
	EpidemicCard(string n, char c, int a);

	~EpidemicCard();

	void playCard(InfectionDeck& deck); //pass the infection deck
};

