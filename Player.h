
#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Role.h"
#include "CityCard.h"
#include "ReferenceCard.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
/**#include "boost_1_63_0/boost/archive/text_oarchive.hpp"
#include "boost_1_63_0boost/archive/text_iarchive.hpp"**/

using namespace std;


class Player
{
    public:
        Player(char p, vector<Role> &roleDeck, vector<Card*> &deck, int pCount, int id);
        Player();
        ~Player();

        void printPossessions();
        void printReference();
        void displayHand();
        void displayActionsLeft();
        
        vector<Card*> getHand();
        void setHand(vector<Card*> c);
        Role getRole();
        char getPawn();
        int getId();
        int getLocation();

        //actions
        //void move(Map m);
		void move(int d); //replace this later
		void flight(int a);
        void buildStation(Map m);
        void treatDisease(Map m);
        void shareKnowledge(Player target);
        void discoverCure(char diseaseColor);
        void activateAbility(vector<Card> &deck);

        //automatic mandatory actions
        void startTurn();
        void subtractAction();
        void concludeTurn(vector<Card*> deck);
        void drawCards(vector<Card*> deck, int num);
        bool checkAction();
	void discard(int a);

        //passive effects check
        void checkPassiveRole();

        //save and load functions
        void savePlayer();
        void loadPlayer(string filename);

        //pawn color enum type
        enum pawnColors {BLACK, GREEN, BLUE, RED, YELLOW};

    private:   
        int id;
        int location; //shold be replaced in later versions by a node
        pawnColors pawn;
        vector <Card*> cards;
        Role role;
        int actionsLeft;
        ReferenceCard rc;

       /** friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & id;
            ar & location;
            ar & pawn;  
            ar & cards;
            ar & role;
            ar & actionsLeft;
            ar & rc;
        }*/
#endif 