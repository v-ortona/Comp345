#include "Map.h"
#include "InfectionDeck.h"
#include <iostream>
#include <algorithm>
#include "Player.h"
using namespace std;

int main(int argc, char* argv[])
{
	// game setup 1 Load (from file) and display the game map (board), with connected cities.
	// 	Place the outbreaks marker on the “0” space of the outbreaks track.

	Map newMap = Map(48);
	newMap.startGame();

	//ifstream file("save.txt");
	//newMap.loadMap(ifstream("save.txt")); //LOADING DOESNT WORK

	//newMap.saveMap(); //saves in visual studio folder

	newMap.showMap();



	// game setup 2. Load(from files) a pawn, player cards, reference cards, the 6 research stations and the disease
	// cubes, separate the cubes by color, and place the research station in Atlanta.

	City atlanta = newMap.getCity(7);
	atlanta.setResearchCenter(true);



	// game setup 3. Place the 4 cure markers, side	up near the discovered cure indicators.
	cout << "CURES: " << newMap.blueCure << ", " << newMap.yellowCure << ", " << newMap.whiteCure << ", " << newMap.redCure << endl;


	// game setup 4. Give each player a reference card.
	Player player1 = Player();
	Player player2 = Player();


	// game setup 5. Shuffle the Role cards and deal 1 face up in front of each player.


	// game setup 6. Place the matching colored pawns for these roles in Atlanta.Remove from the game the
	//remaining role cards and pawns.

	cout << "Player 1 at " << newMap.cities[player1.getLocation()]->getName() << endl;
	cout << "Player 2 at " << newMap.cities[player2.getLocation()]->getName() << endl;


	// game setup 7. Take the Epidemic cards out the Player Deck and set them aside.

	vector<Card*> playerDeck;
	for (int i = 0; i < newMap.cities.size(); i++) {
		CityCard* ccard = new CityCard(newMap.cities[i]);
		Card* card = new Card();
		card = ccard;
		playerDeck.push_back(card);
	}

	// game setup 8. Shuffle the other Player cards(city and event cards). //use random_shuffle()

	random_shuffle(playerDeck.begin(), playerDeck.end());


	// game setup 9. Deal cards to the players to form their initial hands.Give cards according to the number of
	//players(1 - player game - 4 cards, 3 - player game - 3 cards, 4 - player game - 2 cards).
	cout << "How many players do you want to play?" << endl;
	int a;
	int playerNum;
	while (a >= 4 || a==0)
	{
		cin >> a;
	}
	switch (a)
	{
		case 1:
			cout << "you have selected 2" << endl;
			playerNum = 2;
			break;
		case 2:
			cout << "you have selected 2" << endl;
			playerNum = 2;
			break;
		case 3:
			cout << "you have selected 2" << endl;
			playerNum = 2;
			break;
		case 4:
			cout << "you have selected 2" << endl;
			playerNum = 2;
			break;
	}

	player1.drawCards(playerDeck, 4);
	player1.printPossessions();

	player2.drawCards(playerDeck, 4);
	player2.printPossessions();

	// game setup 10. Place the infection rate marker and infect 9 cities.9 citi

	//Infection deck initialization
	cout << "INITIALIZING DECK" << endl;
	InfectionDeck ideck = InfectionDeck(newMap.cities);
	ideck.init(48);
	ideck.initialInfection();



	cout << "pls work" << endl;


	bool gameover = false;

	while (!gameover) {

		/////////////PLAYER 1 TURN/////////////
		player1.startTurn();
		cout << "------------------PLAYER 1 TURN------------------" << endl;
		while (player1.checkAction())
		{
			cout << "Player 1 at " << newMap.cities[player1.getLocation()]->getName() << endl;
			cout << "Player 1: Choose your action..." << endl;
			player1.displayActionsLeft();
			cout << "1. Drive/Ferry" << endl;
			cout << "2. Direct Flight" << endl;
			cout << "3. Charter Flight" << endl;
			cout << "4. Shuttle Flight" << endl;
			cout << "5. Build a Research Station" << endl;
			cout << "6. Treat Disease" << endl;
			cout << "7. Share Knowledge" << endl;
			cout << "8. Discover a Cure" << endl;
			char action;
			cin >> action;

			switch (action) {
			case '1':	//Drive/Ferry
			{
				newMap.showCity(player1.getLocation());
				int city;
				cin >> city;
				player1.move(city);

				//player1.move(newMap);
				break;
			}
			case '2':	//Direct Flight: Discard a City card to move to the city named on the card.
			{
				player1.displayHand();

				int cardInt;

				cin >> cardInt;

				player1.flight(player1.getHand()[cardInt]->getId());

				player1.discard(cardInt);
				break;
			}
			case '3':	//Charter Flight: Discard the City card that matches the city you are in to move to any city.
			{
				player1.displayHand();

				int cardInt;

				cin >> cardInt;

				if (player1.getHand()[cardInt]->getId() == player1.getLocation())
				{
					player1.flight(player1.getHand()[cardInt]->getId());

					player1.discard(cardInt);
				}
				break;
			}
			case '4': //Shuttle Flight	Move from a city with a research station to any other city that has a research station.
			{
				City* location = newMap.accessCity(player1.getLocation());

				if (location->researchCenter == true)
				{

					for (int i = 0; i < 47; i++)
					{
						City* newLoc = newMap.accessCity(i);
						if (newLoc->researchCenter == true)
						{
							cout << newLoc->accessCity() << newLoc->getName();
						}
					}
					int newLocation;
					cout << "Enter the ID of the city you want to move to:" << endl;
					cin >> newLocation;

					player1.flight(player1.getHand()[newLocation]->getId());

				}
				break;
			}
			case '5': //Build a Research Station

			{
				player1.displayHand();

				int cardInt;

				cin >> cardInt;

				City* location = newMap.accessCity(player1.getLocation());

				player1.treatDisease(newMap);

				player1.discard(cardInt);

				break;

			}

			case '6':
				//Treat Disease

			{
				City* location = newMap.accessCity(player1.getLocation());

				player1.treatDisease(newMap);

				break;
			}

			case '7':/* SHARE KNOWLEDGE	Don't forget that if the player who gets the card now has more than 7 cards, that player must
					immediately discard a card or play an Event card(see Event Cards on page 7).*/

			{
				player1.shareKnowledge(player2);


				break;
			}

			case '8'://Discover a Cure
				/*At any research station, discard 5 City cards of the same color from your hand to 
				cure the disease of that color. Move the disease’s cure marker to its cure Indicator.
				If no cubes of this color are on the board, this disease is now eradicated.
				Flip its cure marker from its “vial” side to its “ ” side.*/
			{

				player1.displayHand();

				int cardInt1, cardInt2, cardInt3, cardInt4, cardInt5;

				cout << "Enter the ID of the cards you want to discard:" << endl;

				cin >> cardInt1 >> cardInt2 >> cardInt3 >> cardInt4 >> cardInt5;

				player1.treatDisease(newMap);

				player1.discard(cardInt1);
				player1.discard(cardInt2);
				player1.discard(cardInt3);
				player1.discard(cardInt4);
				player1.discard(cardInt5);
				
				break;
			}
			}
		}
		
			
			

		////////////END TURN / DRAW 2 PLAYER CARDS////////////
		player1.concludeTurn(playerDeck);



		/////////////INFECT CITIES///////////////
		cout << "------------------INFECTION TURN------------------" << endl;
		cout << "Cubes remaining: " << InfectionDeck::infectionCubes << ", Outbreaks: " << InfectionDeck::numberOutbreaks << ", Marker position: " << InfectionDeck::infectionMarker << "(" << InfectionDeck::markerValues[InfectionDeck::infectionMarker] << ")" << endl;
		ideck.playInfection();
		if (InfectionDeck::infectionCubes < 0) {
			//gameover = true;
			cout << "GAME OVER: You have run out of infection cubes" << endl;
			break;
		}
		if (InfectionDeck::numberOutbreaks >= 8) {
			//gameover = true;
			cout << "GAME OVER: Too many outbreaks have occurred" << endl;
			break;
		}




		/////////////PLAYER 2 TURN/////////////
		player2.startTurn();
		cout << "------------------PLAYER 2 TURN------------------" << endl;
		while (player2.checkAction())
		{
			cout << "Player 2 at " << newMap.cities[player2.getLocation()]->getName() << endl;
			cout << "Player 2: Choose your action..." << endl;
			player2.displayActionsLeft();
			cout << "1. Drive/Ferry" << endl;
			cout << "2. Direct Flight" << endl;
			cout << "3. Charter Flight" << endl;
			cout << "4. Shuttle Flight" << endl;
			cout << "5. Build a Research Station" << endl;
			cout << "6. Treat Disease" << endl;
			cout << "7. Share Knowledge" << endl;
			cout << "8. Discover a Cure" << endl;
			char action;
			cin >> action;

			switch (action) {
			case '1':	//Drive/Ferry
			{
				newMap.showCity(player2.getLocation());
				int city;
				cin >> city;
				player2.move(city);
				break;
			}
			case '2':	//Direct Flight: Discard a City card to move to the city named on the card.
			{
				player2.displayHand();

				int cardInt;

				cin >> cardInt;

				player2.flight(player2.getHand()[cardInt]->getId());

				player2.discard(cardInt);
				break;
			}
			case '3':	//Charter Flight: Discard the City card that matches the city you are in to move to any city.
			{
				player2.displayHand();

				int cardInt;

				cin >> cardInt;

				if (player2.getHand()[cardInt]->getId() == player2.getLocation())
				{
					player2.flight(player2.getHand()[cardInt]->getId());

					player2.discard(cardInt);
				}
				break;
			}
			case '4': //Shuttle Flight	Move from a city with a research station to any other city that has a research station.
			{
				City* location = newMap.accessCity(player2.getLocation());

				if (location->researchCenter == true)
				{

					for (int i = 0; i < 47; i++)
					{
						City* newLoc = newMap.accessCity(i);
						if (newLoc->researchCenter == true)
						{
							cout << newLoc->accessCity() << newLoc->getName();
						}
					}
					int newLocation;
					cout << "Enter the ID of the city you want to move to:" << endl;
					cin >> newLocation;

					player2.flight(player2.getHand()[newLocation]->getId());

				}
				break;
			}
			case '5': //Build a Research Station

			{
				player2.displayHand();

				int cardInt;

				cin >> cardInt;

				City* location = newMap.accessCity(player2.getLocation());

				player2.treatDisease(newMap);

				player2.discard(cardInt);

				break;

			}

			case '6':
				//Treat Disease

			{
				City* location = newMap.accessCity(player2.getLocation());

				player2.treatDisease(newMap);

				break;
			}

			case '7':/* SHARE KNOWLEDGE	Don't forget that if the player who gets the card now has more than 7 cards, that player must
					 immediately discard a card or play an Event card(see Event Cards on page 7).*/

			{
				player2.shareKnowledge(player1);


				break;
			}

			case '8'://Discover a Cure
				/*At any research station, discard 5 City cards of the same color from your hand to
				cure the disease of that color. Move the disease’s cure marker to its cure Indicator.
				If no cubes of this color are on the board, this disease is now eradicated.
				Flip its cure marker from its “vial” side to its “ ” side.*/
			{

				player2.displayHand();

				int cardInt1, cardInt2, cardInt3, cardInt4, cardInt5;

				cout << "Enter the ID of the cards you want to discard:" << endl;

				cin >> cardInt1 >> cardInt2 >> cardInt3 >> cardInt4 >> cardInt5;

				player2.treatDisease(newMap);

				player2.discard(cardInt1);
				player2.discard(cardInt2);
				player2.discard(cardInt3);
				player2.discard(cardInt4);
				player2.discard(cardInt5);

				break;
			}
			}
		}




		////////////END TURN / DRAW 2 PLAYER CARDS////////////
		player2.concludeTurn(playerDeck);



		/////////////INFECT CITIES///////////////
		cout << "------------------INFECTION TURN------------------" << endl;
		cout << "Cubes remaining: " << InfectionDeck::infectionCubes << ", Outbreaks: " << InfectionDeck::numberOutbreaks << ", Marker position: " << InfectionDeck::infectionMarker << "(" << InfectionDeck::markerValues[InfectionDeck::infectionMarker] << ")" << endl;
		ideck.playInfection();
		if (InfectionDeck::infectionCubes < 0) {
			//gameover = true;
			cout << "GAME OVER: You have run out of infection cubes" << endl;
			break;
		}
		if (InfectionDeck::numberOutbreaks >= 8) {
			//gameover = true;
			cout << "GAME OVER: Too many outbreaks have occurred" << endl;
			break;
		}

	}


	system("pause"); //windows only
	return 0;
}	
