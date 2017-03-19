#include "Card.h"

Card::Card(string n, char c, int i)
{
    this->name = n;
    this->color = c;
    this->id = i;
}

Card::Card()
{
    this->name = "null";
    this->color = '0';
    this->id = 0;
}
Card::~Card(){}

string Card::getName()
{
    return this->name;
}

char Card::getColor()
{
    return this->color;
}

int Card::getId()
{
    return this->id;
}


void Card::printCard()
{
    cout<<"name: "<<name<<endl;
    cout<<"color: "<<color<<endl;
    cout<<"id: "<<id<<endl;
}
