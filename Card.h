#include <string>
#include <iostream>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card
{
    public:
        Card();
        Card(string n, char c, int i);
        ~Card();

        string getName();
        char getColor();
        int getId();
        void setName(string n);
        void setColor(char c);
        void setId(int i);

        void printCard();

    private:
        string name;
        char color;
        int id;

};
#endif