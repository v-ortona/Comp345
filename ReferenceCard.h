#include <string>
#include <iostream>
using namespace std;

#ifndef REFERENCECARD_H
#define REFERENCECARD_H

class ReferenceCard{
    public:
        ReferenceCard();
        ~ReferenceCard();
        void displayCard();

    private:
        string description;

};
#endif