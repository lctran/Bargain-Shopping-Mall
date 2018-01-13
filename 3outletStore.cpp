#include "3outletStore.hpp"


void outletStore::storeItems() {
    outlet1.itemName = "Navy v-Neck Shirt";
    outlet1.price = 10;
    outlet1.type = "tops";
    outletInventory.push_back(outlet1);

    outlet2.itemName = "Grey Long Sleeve + Black Bomber Jacket";
    outlet2.price = 60;
    outlet2.type = "tops";
    outletInventory.push_back(outlet2);

    outlet3.itemName = "Khaki Joggers";
    outlet3.price = 40;
    outlet3.type = "bottoms";
    outletInventory.push_back(outlet3);

    outlet4.itemName = "Basic Blue Jeans";
    outlet4.price = 40;
    outlet4.type = "bottoms";
    outletInventory.push_back(outlet4);
}

// Location #3 - no NORTH, EAST
space *outletStore::moveSpace(space *currentSpace, int direction) {
    space *newSpace;

    switch (direction - 1) {
    case n:
	   cout << "No store NORTH of here. Let's go SOUTH instead." << endl;
    case s:
	   newSpace = currentSpace->south;
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

void outletStore::viewItems() {
    cout << " Outlet Clothing Available " << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < outletInventory.size(); i++)
	   cout << i + 1 << " - " << outletInventory[i].itemName << "  $" << outletInventory[i].price << endl;
    cout << "---------------------------" << endl;
}

double outletStore::getItemPrice() {
    return tempItem.price;
}

double outletStore::calculateItemCost() {
    cout << "Enter OUTLET CLOTHING # Choice:  ";
    cin >> choice;
    choice = validateFloat(choice, 1, outletInventory.size());

    if (choice == 1)
	   tempItem = outlet1;
    else if (choice == 2)
	   tempItem = outlet2;
    else if (choice == 3)
	   tempItem = outlet3;
    else if (choice == 4)
	   tempItem = outlet4;

    if (randomSale == 1)		  // $5 OFF CLOTHING sale
	   tempItem.price -= 5;
    else if (randomSale == 2)	  // 50% OFF CLOTHING sale
	   tempItem.price /= 2;
    else if (randomSale == 3)	  // 75% OFF CLOTHING sale
	   tempItem.price /= 4;

    return tempItem.price;
}

// if player has enough money add to myCloset vector
item outletStore::buyItems() {
    return tempItem;
}

void outletStore::storeFrontMenu() {
    cout << " Welcome to the OUTLET STORE  " << endl;
    cout << "******************************" << endl;
    sales();		// display possible sales before giving user option to shop or leave
    spaceMenu();	// 1=shop, 2=leave, user input stored in choiceDir variable
    viewItems();	// display options

				// person obj will do if/else for choice dir

}

void outletStore::sales() {
    cout << "Today's new OUTLET CLOTHING sale:  ";
    randomSale = rand() % 3 + 1;		// range 1-3

    switch (randomSale) {
    case 1:
	   cout << "$5 OFF CLOTHES (limit 1)" << endl;
	   break;
    case 2:
	   cout << "50% OFF CLOTHES (limit 1)" << endl;
	   break;
    case 3:
	   cout << "75% OFF CLOTHES (limit 1)" << endl;
	   break;
    }
    cout << "Prices will be reflected at checkout." << endl;
}