#include "Card.h"
#include "Role.h"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(char p, Role roleDeck[], Card cardDeck[], int pCount, int roleNum);
        Player();
        ~Player();

        void printPlayerPossessions();
        void printReference();
        void displayHand();
        
        //actions
        void move(int destination);
        void buildStation();
        void treatDisease();
        void shareKnowledge(Player target);
        void discoverCure(char diseaseColor);
        void activateAbility(Card deck[]);

        //automatic mandatory actions
        void startTurn();
        void subtractAction();
        void concludeTurn(Card deck[]);
        void drawCards(Card deck[], int num);
        bool checkAction();

        //passive effects check
        void checkPassiveRole();

    private:   
        int location; //shold be replaced in later versions by a node
        char pawn;
        Card[] cards;
        Role role;
        int actionsLeft;
};
#endif 