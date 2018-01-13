

#ifndef BEAUTYSTORE_HPP
#define BEAUTYSTORE_HPP

#include "space.hpp"

class beautyStore : public space {
public:
    beautyStore() : space() {
	   this->locationName = "Beauty Store";
	   locationNumber = 6;
	   storeItems();
    }

    virtual void storeItems();	 // items each store carries, hard coded
    virtual space *moveSpace(space *currentSpace, int direction); // int dir = enum
    virtual void viewItems();	 // view clothes/shoes in store
    virtual double calculateItemCost();
    virtual item buyItems();	 // add items to closet
    virtual void storeFrontMenu(); // menu per space, for user interaction
    virtual void sales();		 // determine if there is a sale that day
    virtual double getItemPrice();

private:
    item beauty1, beauty2, beauty3, beauty4; // number of items in store
    vector<item> beautyInventory;

    double tempSaleCalculation;
};

#endif