<<<<<<< HEAD
#include "Player.h"

Player::Player(char p, vector<Role> &roleDeck, vector<Card*> &cardDeck, int pCount, int i)
{
    this->location = 7; //Atlanta is location 7
    this->cards = vector<Card*>(20);
=======
#include <iostream>
#include "Player.h"

Player::Player(char p, Role roleDeck[], Card cardDeck[], int pCount, int roleNum)
{
    location = 1; //Atlanta is location 1
    cards = new Card[20];
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
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
<<<<<<< HEAD
    this->role = roleDeck[roleDeck.size()-1];
    roleDeck.pop_back();
    switch(p)
    {
        case 'b':
               this->pawn = BLUE;
               break;

        case 'g':
               this->pawn = GREEN;
               break;

        case 'r':
               this->pawn = RED;
               break;

        case 'y':
               this->pawn = YELLOW;
               break;
            
        case 'x':
                this->pawn = BLACK;
                break;    
        
    }
    this->rc = ReferenceCard();
    this->id= i;
=======
    role = roleDeck[roleNum];
    pawn = p;
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
}

Player::Player()
{
<<<<<<< HEAD
    this->location = 7;
    this->cards = vector<Card*>();
    this->role = Role();
    this->pawn = BLACK;
    this->rc = ReferenceCard();
    this->id = 0;
}
Player::~Player()
{
    this->cards.clear();
}

vector<Card*> Player::getHand()
{
    return this->cards;
}

void Player::setHand(vector<Card*> c)
{
    this->cards=c;
}

Role Player::getRole()
{
    return this->role;
}

char Player::getPawn()
{
    switch(this->pawn)
    {
        case BLUE:
        return 'b';

        case RED:
        return 'r';

        case YELLOW:
        return 'y';

        case GREEN:
        return 'g';

        case BLACK:
        return 'x';

        default:
        return 'x';
    }
}

int Player::getId()
{
    return this->id;
}

int Player::getLocation()
{
    return this->location;
}


///////////PRINT FUNCTIONS/////////////////////

void Player::printPossessions()
{
    cout<<"Player id: "<<this->id<<endl;
    cout<<"Player location: "<<this->location<<endl;
    switch(this->pawn)
    {
        case BLUE:
        cout<<"Player pawn: blue"<<endl;
        break;

        case RED:
        cout<<"Player pawn: red"<<endl;
        break;

        case YELLOW:
        cout<<"Player pawn: yellow"<<endl;
        break;

        case GREEN:
        cout<<"Player pawn: green"<<endl;
        break;

        default:
        cout<<"Player pawn: black"<<endl;;
    }

    cout<<"Player cards: "<<endl;
    this->displayHand();
    cout<<"Player Role: "<<this->role.getName()<<endl;
    cout<<"Player reference card: "<<endl;
    this->printReference();
}

void Player::displayHand()
{
    for(int i=0; i<cards.size(); i++)
    {
        cout<<"Card at index "<< i <<": "<<cards[i]->getName()<<endl;
    }
}

void Player::printReference()
{
    this->rc.displayCard();
}

void Player::displayActionsLeft()
{
    cout<<"Actions remaining: "<<this->actionsLeft<<endl;
}
//////////AUTOMATIC ACTIONS//////////////////
void Player::startTurn()
{
    actionsLeft=4;
}

void Player::subtractAction()
{
    actionsLeft--;
}

void Player::concludeTurn(vector<Card*> deck)
{
    this->drawCards(deck, 2);
}

void Player::drawCards(vector<Card*> deck, int num)
{
    int userCards = this->cards.size(); //number of cards in user hand
    int lastCard = deck.size(); //index of last card
    if(lastCard == 0) //if deck runs out
=======
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
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
    {
        //game over
    }

    else //draw
    {
        for(int a = 0; a < num; a++)
        {
<<<<<<< HEAD
            this->cards.push_back(deck.back());
            deck.pop_back();
=======
            cards[userCards + a] = deck[lastCard - a];
            deck[lastCard - a] = 0;
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
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

<<<<<<< HEAD
void Player::discard(int a)
{
	//vector<Card*> cards = this->getHand(); //does it make a copy
	//cards[a] = cards.back();
	//cards.pop_back();

	this->cards[a] = this->cards.back();
	this->cards.pop_back();
}
=======

>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905

////////PLAYER ACTIONS/////////////////////////////////
void Player::move(int d)
{
<<<<<<< HEAD
	
    //only drive movement is available.
    /*vector<City*> cities= m.getConnectedCities(this->location);
    vector<int> cityIndex;
    bool correctInput=false;
    int choice;
    cout<<"select the index of the city you would like to drive (or fly) to: "<<endl;
    for (int i=0; i<cities.size(); i++) //get possible cities player can drive to
    {
        cout<< cities[i]->index << " : " << cities[i]->getName()<<endl;
        cityIndex.push_back(cities[i]->index);
    }
    cities.clear();

    while(!correctInput) //get player input with verification
    {
        cin>>choice;
        for (int i=0; i<cityIndex.size(); i++)
        {
            if(choice==cityIndex[i])
                correctInput = true;
        }
        if(!correctInput)
            cout<<"sorry, you have entered an invalid index"<<endl;
    }
    this->location = choice;

    this->subtractAction();
	
	*/
	if (Player::checkAction())
	{
		location = d;
		this->subtractAction();
	}
}

void Player::flight(int a)
{
	int choice;

	choice = a;

	this->location = choice;

	this->subtractAction();
}

void Player::buildStation(Map m)
{
    //uses current player location, builds a station
    if(m.researchStationNum>0)
    {
        int loc=this->location;
        City c;
        City* cp = m.accessCity(loc); // gets a pointer to city where player is
        c = *cp;                      //creates a copy that can be modified
        c.setResearchCenter(true);    // copy modified
        *cp = c;                      //city replaced with copy
        delete[] cp;

        m.researchStationNum--;
        this->subtractAction();
    }
    else
    {
        //no more research stations can be built
    }
}

void Player::treatDisease(Map m)
{
        int loc=this->location;
        City c;
        char cityColor;
        City* cp = m.accessCity(loc);
        c= *cp;
        cityColor= c.getColor();        
        if(c.infected == true) //if the city has infection cubes
        {   
            if((cityColor=='b' && m.blueCure) || (cityColor=='y' && m.yellowCure) || (cityColor=='w' && m.whiteCure) || (cityColor=='r' && m.redCure))
            {   //if cure for city is discovered
                c.setInfectionLevel(0);
                c.setInfection(false);
            }
            else
            {
                c.decrementInfection();
                if(c.getInfection()==0)
                    c.setInfection(false);
            }
            *cp = c;
            this->subtractAction();
        }
        else
        {
            //city has no infection to remove
        }
        delete[] cp;
=======
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
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
}

void Player::shareKnowledge(Player tg)
{
<<<<<<< HEAD
    if(this->checkAction())
    {
        char option;
        int index;
        vector<Card*> newHand;
        if(this->location == tg.getLocation())
        {
            cout<<"Press 't' to take a card, and 'g' to give one"<<endl;
            cin>>option;
            if(option == 't')
            {
                cout<<"Player"<<tg.getId()<<"s hand: "<<endl;
                tg.displayHand();
                cout<<"Enter the index you want to take the card from"<<endl;
                cin>>index;
                (this->cards).push_back(tg.getHand()[index]);   //adds card to hand of this player
                newHand=tg.getHand();                           //creates new hand for tg
                newHand.erase(newHand.begin() + index);         //removes card from new hand
                tg.setHand(newHand);                            //replaces old hand of tg
                this->subtractAction();
            }
            else if(option == 'g')
            {
                cout<<"Player"<<this->id<<" hand: "<<endl;
                this->displayHand(); 
                cout<<"Enter the index you want to take the card from"<<endl;
                cin>>index;
                newHand = tg.getHand();                             //similar logic
                newHand.push_back((this->getHand())[index]);
                tg.setHand(newHand);
                (this->cards).erase((this->cards).begin() + index);
                this->subtractAction();
            }
            else
            {
                cout<<"Invalid Option. Try again."<<endl;
            }   
            cout<<"Player"<<this->id<<" select the card you want "<<endl;
        }

        else
        {
            cout<<"sorry, this player is not on this space"<<endl;
        }
    } 
=======
    //trades a city card with player tg
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
}

void Player::discoverCure(char diseaseColor)
{
<<<<<<< HEAD
    int count=0;
    for (int i=0; i<(this->cards).size(); i++) //counts number of cards with appropriate disease color
    {
        if ((this->cards)[i]->getColor()==diseaseColor)
            count++;
    }
    if(count>4)
    {
        //disease cured
        this->subtractAction();
    }
    else
    {
        cout<<"not enough cards to cure that disease"<<endl;
    }
}

void Player::activateAbility(vector<Card> &deck)
=======
    //treats a disease if diseaseColor matches the color of 4 cards
}

void Player::activateAbility(Card deck[])
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
{
    //activates a player ability based on their role
}

///////////PASSIVE ROLE ABILITY/////////////////
void Player::checkPassiveRole()
{
    //activates a passive ability based on the Players role. 
}

<<<<<<< HEAD
/*
void Player::savePlayer()
{
    string fullPath;
    stringstream playerId; //set dynamic file name unique to the player
    playerId << this->id;
    fullPath.append("PlayerSave"); 
    fullPath.append(playerId.str());
    fullPath.append(".txt");

    ofstream myFile(fullPath.c_str(), ios::binary);
    boost::archive::text_oarchive oa(myFile);
    oa << this;

	myFile.close();	
}

void Player::loadPlayer(string fileName)
{
    Player pl;
    char c;
    ifstream home(fileName);
    boost::archive::text_iarchive ia(home);
    ia >> pl;
    home.close();

    this->id = pl.getId();
    this->cards = pl.getHand();
    this->role = pl.getRole();
    c= pl.getPawn();
    switch(p)
    {
        case 'b':
               this->pawn = BLUE;
               break;

        case 'g':
               this->pawn = GREEN;
               break;

        case 'r':
               this->pawn = RED;
               break;

        case 'y':
               this->pawn = YELLOW;
               break;
            
        case 'x':
                this->pawn = BLACK;
                break;    
        
    }*/
=======
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
>>>>>>> 19a1acb3e3cf43710a55658f0a4e517fa0657905
