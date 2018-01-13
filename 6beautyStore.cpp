#include "6beautyStore.hpp"


void beautyStore::storeItems() {
    beauty1.itemName = "Vampy Lipstick + Lipliner Set";
    beauty1.price = 35;
    beauty1.type = "beauty";
    beautyInventory.push_back(beauty1);

    beauty2.itemName = "Light Blue Perfume";
    beauty2.price = 75;
    beauty2.type = "beauty";
    beautyInventory.push_back(beauty2);

    beauty3.itemName = "Eternity Cologne";
    beauty3.price = 60;
    beauty3.type = "beauty";
    beautyInventory.push_back(beauty3);

    beauty4.itemName = "Hair Gel + Wooden Comb Set";
    beauty4.price = 40;
    beauty4.type = "beauty";
    beautyInventory.push_back(beauty4);
}

// Location #4 - no EAST, SOUTH
space *beautyStore::moveSpace(space *currentSpace, int direction) {
    space *newSpace;

    switch (direction - 1) {
    case s:
	   cout << "No store SOUTH of here. Let's go NORTH instead." << endl;
    case n:
	   newSpace = currentSpace->north;
	   break;
    case e:
	   cout << "No store EAST of here. Let's go WEST instead." << endl;
    case w:
	   newSpace = currentSpace->west;
	   break;
    default:
	   cout << "You ended up staying in same store." << endl;
	   newSpace = currentSpace;
    }

    return newSpace;
}

void beautyStore::viewItems() {
    cout << " Beauty Products Available " << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < beautyInventory.size(); i++)
	   cout << i + 1 << " - " << beautyInventory[i].itemName << "  $" << beautyInventory[i].price << endl;
    cout << "-----------------------" << endl;
}

double beautyStore::getItemPrice() {
    return tempItem.price;
}

double beautyStore::calculateItemCost() {
    cout << "Enter BEAUTY Product # Choice:  ";
    cin >> choice;
    choice = validateFloat(choice, 1, beautyInventory.size());

    if (choice == 1)
	   tempItem = beauty1;
    else if (choice == 2)
	   tempItem = beauty2;
    else if (choice == 3)
	   tempItem = beauty3;
    else if (choice == 4)
	   tempItem = beauty4;

    if (randomSale == 2)		  // $15 OFF BEAUTY ITEMS
	   tempItem.price -= 15;
    else if (randomSale == 3)	  // $5 OFF ACCESSORIES
	   tempItem.price -= 5;

    return tempItem.price;
}

// if player has enough money add to myCloset vector
item beautyStore::buyItems() {
    return tempItem;
}

void beautyStore::storeFrontMenu() {
    cout << " Welcome to the BEAUTY STORE  " << endl;
    cout << "******************************" << endl;
    sales();		// display possible sales before giving user option to shop or leave
    spaceMenu();	// 1=shop, 2=leave, user input stored in choiceDir variable
    viewItems();	// display options

				// person obj will do if/else for choice dir

}

void beautyStore::sales() {
    cout << "Today's new BEAUTY sale:  ";
    randomSale = rand() % 3 + 1;		// range 1-3

    switch (randomSale) {
    case 1:
	   cout << "None" << endl;
	   break;
    case 2:
	   cout << "$15 OFF BEAUTY PRODUCTS (limit 1)" << endl;
	   break;
    case 3:
	   cout << "$5 OFF BEAUTY PRODUCTS (limit 1)" << endl;
	   break;
    }
    cout << "Prices will be reflected at checkout." << endl;
}