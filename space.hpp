// abstract class
#ifndef SPACE_HPP
#define SPACE_HPP

//#include "player.hpp"
//#include "gameplay.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>		   // rand()
#include <time.h>		   // srand(time(NULL))
#include <cctype>		   // isdigit() vaildateFloat()
using namespace std;

struct item {
    double price;
    string type;
    string itemName;
};

class space {
public:
    space *north;
    space *east;
    space *south;
    space *west;

    space();			   // default constructor
    ~space();			   // destructor

    virtual void storeItems() = 0;	 // items each store carries, hard coded
    virtual space *moveSpace(space *currentSpace, int direction) = 0; // int dir = enum
    virtual void viewItems() = 0;	 // view clothes/shoes in store
    virtual double calculateItemCost() = 0;
    virtual item buyItems() = 0;	 // add items to closet
    virtual void storeFrontMenu() = 0; // menu per space, for user interaction
    virtual void sales() = 0;		 // determine if there is a sale that day
    virtual double getItemPrice() = 0;

    double getChoiceDir();
    double getChoice();
    string getLocationName();
    void spaceMenu();
    //void movePrompt();
    void viewCloset();

    double validateFloat(double, int, int);

protected:
    vector<item> myCloset;  // store items bought
    item tempItem;
    double itemPrice;

    int locationNumber;	   // 1-6
    string locationName;
    int randomSale;		   // random number generated to determine a sale for store

    enum directions { n, e, s, w };

    double choice;		   // input validation, override each time no big deal
    double choiceDir;

};

#endif