

#ifndef CLOTHINGSTORE_HPP
#define CLOTHINGSTORE_HPP

#include "space.hpp"

class clothingStore : public space {
public:
    clothingStore() : space() {
	   this->locationName = "Clothing Store";
	   locationNumber = 2;
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
    item cloth1, cloth2, cloth3, cloth4; // number of items in store, adjust in relation to shoeItems()
    vector<item> clothingInventory;

    double tempSaleCalculation;
};

#endif