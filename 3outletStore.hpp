

#ifndef OUTLET_HPP
#define OUTLET_HPP

#include "space.hpp"

class outletStore : public space {
public:
    outletStore() : space() {
	   this->locationName = "Outlet Store";
	   locationNumber = 3;
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
    item outlet1, outlet2, outlet3, outlet4; // number of items in store
    vector<item> outletInventory;

    double tempSaleCalculation;
};

#endif