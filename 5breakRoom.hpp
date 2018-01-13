

#ifndef BREAKROOM_HPP
#define BREAKROOM_HPP
#include "space.hpp"

#include <iostream>
#include <cstdlib>		   // rand()
#include <time.h>		   // srand(time(NULL))
#include <cctype>		   // isdigit() vaildateFloat()
using namespace std;

class breakroom : public space {
public:
    breakroom() :space() {
	   this->locationName = "Breakroom";
	   locationNumber = 5;
	   srand(unsigned(time(NULL)));			// random seed generator, unsigned()
    }
   // ~breakroom();

    void breakRoomMenu();
    double playLottery();
    double getLottery();
    int getInput2();
    virtual space *moveSpace(space *currentSpace, int direction); // int dir = enum

    double validateFloat(double, int, int);

    virtual void storeItems();	 // items each store carries, hard coded
    //virtual space *moveSpace(space *currentSpace, int direction); // int dir = enum
    virtual void viewItems();	 // view clothes/shoes in store
    virtual double calculateItemCost();
    virtual item buyItems();	 // add items to closet
    virtual void storeFrontMenu(); // menu per space, for user interaction
    virtual void sales();		 // determine if there is a sale that day
    virtual double getItemPrice();

private:
    double input2;
    int lotteryMultiplier;
    enum directions { n, e, s, w };
};
#endif