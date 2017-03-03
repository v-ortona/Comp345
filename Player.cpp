#include <iostream>
#include "Player.h"

Player::Player(char p, Role roleDeck[], Card cardDeck[], int pCount, int roleNum)
{
    location = 1; //Atlanta is location 1
    cards = new Card[20];
    switch(pCount) //draws cards based on player count
    {
        case 1:
            drawCards(cardDeck, 4);
            break;
        case 2: 
            drawCards(cardDeck, 4);
            break;
        case 3:
            drawCards(cardDeck, 3);
            break;
        case 4:
            drawCards(cardDeck, 2);
            break;
    }
    role = roleDeck[roleNum];
    pawn = p;
}

Player::Player()
{
    location = 0;
    cards = new Card[20];
    role = null;
    pawn = '0';
}
Player::~Player(){}

//////////AUTOMATIC ACTIONS//////////////////
void Player::startTurn()
{
    actionsLeft=4;
}

void Player::subtractAction()
{
    actionsLeft--;
}

void Player::concludeTurn(Card deck[])
{
    this->drawCards(deck[], 2);
}

void Player::drawCards(Card deck[], int num)
{
    int userCards; //number of cards in user hand
    int lastCard; //index of last card
    for (int i=0; i<60; i++) //finds last card in deck
    {
        if(deck[i] == 0) //if position is null
        {
            lastCard = i-1;
            break;
        }
    }

    for (int y=0; y<20; y++) //find first empty slot in users hand
    {
        if(deck[y] == 0) //if position is null
        {
            userCards = y;
            break;
        }
    }

    if(lastCard - num < 0) //if deck runs out
    {
        //game over
    }

    else //draw
    {
        for(int a = 0; a < num; a++)
        {
            cards[userCards + a] = deck[lastCard - a];
            deck[lastCard - a] = 0;
        }
    }
}

/**
*  returns true if the user still has actions left this turn.
*/
bool Player::checkAction()
{
    if(actionsLeft == 0)
        return false;
    else
        return true; 
}



////////PLAYER ACTIONS/////////////////////////////////
void Player::move(int d)
{
    if(Player::checkAction())
    {
        location = d;
        this->subtractAction();
    }                
}

void Player::buildStation()
{
    //uses current player location, builds a station
}

void Player::treatDisease()
{
    //removes a disease cube from current player location
}

void Player::shareKnowledge(Player tg)
{
    //trades a city card with player tg
}

void Player::discoverCure(char diseaseColor)
{
    //treats a disease if diseaseColor matches the color of 4 cards
}

void Player::activateAbility(Card deck[])
{
    //activates a player ability based on their role
}

///////////PASSIVE ROLE ABILITY/////////////////
void Player::checkPassiveRole()
{
    //activates a passive ability based on the Players role. 
}

///////////PRINT FUNCTIONS/////////////////////
void Player::displayHand()
{
    int userCardNum;
    for (int y=0; y<20; y++) //find first empty slot in users hand
    {
        if(deck[y] == 0) //if position is null
        {
            userCardNum = y;
            break;
        }
    }
    for(int i=0; i<userCardNum; i++)
    {
        cout<<"Card at index "<< i <<": "<<cards[i].displayName<<endl;
    }
}