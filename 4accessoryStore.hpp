

#ifndef ACCESSORY_HPP
#define ACCESSORY_HPP

#include "space.hpp"

class accessoryStore : public space {
public:
    accessoryStore() : space() {
	   this->locationName = "Accessory Store";
	   locationNumber = 4;
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
    item accessory1, accessory2, accessory3, accessory4; // number of items in store
    vector<item> accessoryInventory;

    double tempSaleCalculation;
};

#endif