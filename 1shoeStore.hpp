#ifndef SHOESTORE_HPP
#define SHOESTORE_HPP

#include "space.hpp"

class shoeStore : public space {
public:
    shoeStore() : space() {
	   this->locationName = "Shoe Store";
	   locationNumber = 1;
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
    item shoe1, shoe2, shoe3, shoe4; // number of items in store, adjust in relation to shoeItems()
    vector<item> shoeInventory;


};
#endif