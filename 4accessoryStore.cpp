#include "4accessoryStore.hpp"


void accessoryStore::storeItems() {
    accessory1.itemName = "Black Mini Leather Backpack";
    accessory1.price = 35;
    accessory1.type = "accessories";
    accessoryInventory.push_back(accessory1);

    accessory2.itemName = "Sterling Silver Jewelry Set";
    accessory2.price = 100;
    accessory2.type = "accessories";
    accessoryInventory.push_back(accessory2);

    accessory3.itemName = "Silver Smart Watch";
    accessory3.price = 80;
    accessory3.type = "accessories";
    accessoryInventory.push_back(accessory3);

    accessory4.itemName = "Brown Tri-fold Wallet";
    accessory4.price = 40;
    accessory4.type = "accessories";
    accessoryInventory.push_back(accessory4);
}

// Location #4 - no WEST, SOUTH
space *accessoryStore::moveSpace(space *currentSpace, int direction) {
    space *newSpace;

    switch (direction - 1) {
    case s:
	   cout << "No store SOUTH of here. Let's go NORTH instead." << endl;
    case n:
	   newSpace = currentSpace->north;
	   break;
    case w:
	   cout << "No store WEST of here. Let's go EAST instead." << endl;
    case e:
	   newSpace = currentSpace->east;
	   break;
    default:
	   cout << "You ended up staying in same store." << endl;
	   newSpace = currentSpace;
    }

    return newSpace;
}

void accessoryStore::viewItems() {
    cout << " Accessories Available " << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < accessoryInventory.size(); i++)
	   cout << i + 1 << " - " << accessoryInventory[i].itemName << "  $" << accessoryInventory[i].price << endl;
    cout << "-----------------------" << endl;
}

double accessoryStore::getItemPrice() {
    return tempItem.price;
}

double accessoryStore::calculateItemCost() {
    cout << "Enter ACCESSORY # Choice:  ";
    cin >> choice;
    choice = validateFloat(choice, 1, accessoryInventory.size());

    if (choice == 1)
	   tempItem = accessory1;
    else if (choice == 2)
	   tempItem = accessory2;
    else if (choice == 3)
	   tempItem = accessory3;
    else if (choice == 4)
	   tempItem = accessory4;

    if (randomSale == 2)		  // $10 OFF ACCESSORIES
	   tempItem.price -= 10;
    else if (randomSale == 3)	  // $25 OFF ACCESSORIES
	   tempItem.price -= 25;

    return tempItem.price;
}

// if player has enough money add to myCloset vector
item accessoryStore::buyItems() {
    return tempItem;
}

void accessoryStore::storeFrontMenu() {
    cout << " Welcome to the ACCESSORY STORE  " << endl;
    cout << "*********************************" << endl;
    sales();		// display possible sales before giving user option to shop or leave
    spaceMenu();	// 1=shop, 2=leave, user input stored in choiceDir variable
    viewItems();	// display options

				// person obj will do if/else for choice dir

}

void accessoryStore::sales() {
    cout << "Today's new ACCESSORY sale:  ";
    randomSale = rand() % 3 + 1;		// range 1-3

    switch (randomSale) {
    case 1:
	   cout << "None" << endl;
	   break;
    case 2:
	   cout << "$10 OFF ACCESSORIES (limit 1)" << endl;
	   break;
    case 3:
	   cout << "$25 OFF ACCESSORIES (limit 1)" << endl;
	   break;
    }
    cout << "Prices will be reflected at checkout." << endl;
}