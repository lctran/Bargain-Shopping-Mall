#include "2clothingStore.hpp"


void clothingStore::storeItems() {
    cloth1.itemName = "White Longline T-Shirt";
    cloth1.price = 20;
    cloth1.type = "tops";
    clothingInventory.push_back(cloth1);

    cloth2.itemName = "Black Crewneck Sweater";
    cloth2.price = 60;
    cloth2.type = "tops";
    clothingInventory.push_back(cloth2);

    cloth3.itemName = "Grey Cardigan + White Sheer Tank";
    cloth3.price = 80;
    cloth3.type = "tops";
    clothingInventory.push_back(cloth3);

    cloth4.itemName = "Black Jeans";
    cloth4.price = 40;
    cloth4.type = "bottoms";
    clothingInventory.push_back(cloth4);
}

// Location #2 - no NORTH
space *clothingStore::moveSpace(space *currentSpace, int direction) {
    space *newSpace;

    switch (direction - 1) {
    case n:
	   cout << "No store NORTH of here. Let's go SOUTH instead." << endl;
    case s:
	   newSpace = currentSpace->south;
	   break;
    case w:
	   newSpace = currentSpace->west;
	   break;
    case e:
	   newSpace = currentSpace->east;
	   break;
    default:
	   cout << "You ended up staying in same store." << endl;
	   newSpace = currentSpace;
    }

    return newSpace;
}

void clothingStore::viewItems() {
    cout << " Clothing Available " << endl;
    cout << "-----------------" << endl;
    int tempVal = clothingInventory.size(); // fix C4018 error
    for (int i = 0; i < tempVal; i++)
	   cout << i + 1 << " - " << clothingInventory[i].itemName << "  $" << clothingInventory[i].price << endl;
    cout << "-----------------" << endl;
}

double clothingStore::getItemPrice() {
    return tempItem.price;
}

double clothingStore::calculateItemCost() {
    cout << "Enter CLOTHING # Choice:  ";
    cin >> choice;
    choice = validateFloat(choice, 1, clothingInventory.size());

    if (choice == 1)
	   tempItem = cloth1;
    else if (choice == 2)
	   tempItem = cloth2;
    else if (choice == 3)
	   tempItem = cloth3;
    else if (choice == 4)
	   tempItem = cloth4;

    if (randomSale == 2)  // $5 OFF CLOTHING sale
	   tempItem.price -= 5;
    else if (randomSale == 3) { // subtract 25%
	   tempSaleCalculation = tempItem.price / 4;
	   tempItem.price -= tempSaleCalculation;
    }

    return tempItem.price;
}

// if player has enough money add to myCloset vector
item clothingStore::buyItems() {
    /*myCloset.push_back(tempItem);*/
    return tempItem;
}

void clothingStore::storeFrontMenu() {
    cout << " Welcome to the CLOTHING STORE  " << endl;
    cout << "********************************" << endl;
    sales();		// display possible sales before giving user option to shop or leave
    spaceMenu();	// 1=shop, 2=leave, user input stored in choiceDir variable
    viewItems();	// display options

    // person obj will do if/else for choice dir

}

void clothingStore::sales() {
    cout << "Today's new CLOTHING sale:  ";
    randomSale = rand() % 3 + 1;		// range 1-3

    switch (randomSale) {
    case 1:
	   cout << "NONE" << endl;
	   break;
    case 2:
	   cout << "$5 OFF CLOTHES (limit 1)" << endl;
	   break;
    case 3:
	   cout << "25% OFF CLOTHES (limit 1)" << endl;
	   break;
    }
    cout << "Prices will be reflected at checkout." << endl;
}