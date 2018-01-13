#include "player.hpp"

player::player() {
    srand(unsigned(time(NULL)));			// random seed generator, unsigned() C4244 fix
    closetSize = 5;
    bank = 200;
}

player::~player() {
}

double player::getBank() {
    return bank;
}

void player::setBank(double newBalance) {
    bank = newBalance;
}

void player::setMyLocation(space *newSpace) {
    currentSpace = newSpace;
}

space *player::getMyLocation() {
    return currentSpace;
}

void player::purchaseItem(space *store) {
//    int choiceHolder = store->getChoice();

    if (store->getChoice() == 1 && store->calculateItemCost() <= bank && outfit.size() <= 5) {// choose items & verify bank $
	   //store->buyItems();
	   outfit.push_back(store->buyItems());
	   cout << "Bank Balance = " << bank << endl;
	   bank -= store->getItemPrice();
	   cout << "New Bank Balance = " << bank << endl;
	   cout << "Number of Closet Items =  " << outfit.size() << endl;
    }

    if (getOutfitVectorSize() >= closetSize) {
	   cout << "Your closet (bag) is full. The size of your closet is 5 and you have " << outfit.size() << " items." << endl;
    }
	   

    move();
    //store->movePrompt();	   // user input saved into choiceDir
    //setMyLocation(store->moveSpace(getMyLocation(), store->getChoiceDir()));

    //delete store;
}

void player::viewOutfit() {
    cout << " Current Outfit " << endl;
    cout << "----------------" << endl;
    int tempVal = outfit.size(); // fix C4018
    for (int i = 0; i < tempVal; i++)
	   cout << i + 1 << " - " << outfit[i].itemName << "  $" << outfit[i].price << endl;

    if (tempVal == 0)
	   cout << "You have no outfit started. Please continue to bargain shop!" << endl;
    cout << "----------------" << endl;
}

void player::move() {
    cout << "Which direction would you like to go? " << endl;
    cout << "Select one of the following options:  " << endl;
    cout << "--------------------------------------" << endl;
    cout << " 1 - north " << endl;
    cout << " 2 - east " << endl;
    cout << " 3 - south " << endl;
    cout << " 4 - west " << endl;
    cout << "--------------------------------------" << endl;
    cout << " CHOICE:  ";
    cin >> userInput;
    userInput = validateFloat(userInput, 1, 4);	// input validation, change the number of choices
    
    cout << "Current Location:  " << currentSpace->getLocationName() << endl;
    setMyLocation(currentSpace->moveSpace(currentSpace, userInput));
    cout << "New Location:  " << currentSpace->getLocationName() << endl;

}

item player::getOutfitItems(int position) {
    return outfit.at(position);
}

int player::getOutfitVectorSize() {
    return outfit.size();
}
/*********************************************************************
** Description: Handle Floats - To input validate choices within a range
*********************************************************************/
double player::validateFloat(double choice, int lowerLimit, int upperLimit) {
    bool floatNum = false;

    for (int i = lowerLimit; i <= upperLimit; i++) {	// check if it is a whole number
	   if (choice == i) {
		  floatNum = true;
		  break;
	   }
    }

    if (floatNum == false) {							// if not a whole number
	   while (!(choice >= lowerLimit && choice <= upperLimit && floatNum == true) || cin.fail()) {
		  cout << "ERROR! Enter whole digits between " << lowerLimit << " and " << upperLimit << ". What is your choice?" << endl;
		  cout << "NEW INPUT:  ";
		  cin.clear();
		  cin.ignore(100, '\n');
		  cin >> choice;

		  for (int i = lowerLimit; i <= upperLimit; i++) {	// check if it is a whole number re-entered
			 if (choice == i)
				floatNum = true;
		  }

		  if (floatNum == true)
			 break;
	   }
    }

    return choice;
}