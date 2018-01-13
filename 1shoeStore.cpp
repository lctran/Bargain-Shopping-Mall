#include "1shoeStore.hpp"


void shoeStore::storeItems() {
    shoe1.itemName = "Over Knee Boots";
    shoe1.price = 50;
    shoe1.type = "shoes";
    shoeInventory.push_back(shoe1);

    shoe2.itemName = "Chelsea Boots";
    shoe2.price = 80;
    shoe2.type = "shoes";
    shoeInventory.push_back(shoe2);

    shoe3.itemName = "White Air Jordan 1";
    shoe3.price = 150;
    shoe3.type = "shoes";
    shoeInventory.push_back(shoe3);

    shoe4.itemName = "Black Nike Slides";
    shoe4.price = 20;
    shoe4.type = "shoes";
    shoeInventory.push_back(shoe4);
}

// South, East
space *shoeStore::moveSpace(space *currentSpace, int direction) {
    space *newSpace;

    switch (direction - 1) {
    case n:
	   cout << "No store NORTH of here. Let's go SOUTH instead." << endl;
    case s:
	   newSpace = currentSpace->south;
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

void shoeStore::viewItems() {
    cout << " Shoes Available " << endl;
    cout << "-----------------" << endl;
    int tempVal = shoeInventory.size(); // fix C4018
    for (int i = 0; i < tempVal; i++)
	   cout << i + 1 << " - " << shoeInventory[i].itemName << "  $" << shoeInventory[i].price << endl;
    cout << "-----------------" << endl;

}
double shoeStore::getItemPrice() {
    return tempItem.price;
}
double shoeStore::calculateItemCost() {
    cout << "Enter SHOE # Choice:  ";
    cin >> choice;
    choice = validateFloat(choice, 1, shoeInventory.size());

    if (choice == 1)
	   tempItem = shoe1;
    else if (choice == 2)
	   tempItem = shoe2;
    else if (choice == 3)
	   tempItem = shoe3;
    else if (choice == 4)
	   tempItem = shoe4;

    if (randomSale == 2)  // $15 OFF SHOE sale
	   tempItem.price -= 15;
    else if (randomSale == 3)
	   tempItem.price /= 2;
  
    return tempItem.price;
}

// if player has enough money add to myCloset vector
item shoeStore::buyItems() {
    /*myCloset.push_back(tempItem);*/
    return tempItem;
}

void shoeStore::storeFrontMenu() {
    cout << " Welcome to the SHOE STORE  " << endl;
    cout << "****************************" << endl;
    sales();		// display possible sales before giving user option to shop or leave
    spaceMenu();	// 1=shop, 2=leave, user input stored in choiceDir variable
    viewItems();	// display options


    // person obj will do if/else for choice dir
    

}
void shoeStore::sales() {
    cout << "Today's new SHOE sale:  ";
    randomSale = rand() % 3 + 1;		// range 1-3

    switch (randomSale) {
    case 1:
	   cout << "NONE" << endl;
	   break;
    case 2:
	   cout << "$15 OFF SHOES (limit 1)" << endl;
	   break;
    case 3:
	   cout << "50% OFF SHOES (limit 1)" << endl;
	   break;
    }
    cout << "Prices will be reflected at checkout." << endl;

}