#include "5breakRoom.hpp"

//breakroom::breakroom() {
//    srand(unsigned(time(NULL)));			// random seed generator, unsigned() 
//}
//
//breakroom::~breakroom() {
//
//}

void breakroom::breakRoomMenu() {
    cout << " Welcome to the Breakroom " << endl;
    cout << "**************************" << endl;
    cout << "Select one of the following options:  " << endl;
    cout << " 1 - play scratch ticket for $5 " << endl;
    cout << " 2 - go to another store " << endl;
    cout << " 3 - leave and try on clothes [complete challenge] " << endl;
    cout << "CHOICE:  ";
    cin >> input2;
    input2 = validateFloat(input2, 1, 3);

    if (input2 == 1) {
	   cout << "Winning Amount =  " << playLottery() << endl;
    }
   // else if (input2 == 2) in main for option 2 p.move()

}

double breakroom::playLottery() {
    cout << "You will have a chance to win up to $60!" << endl;
    lotteryMultiplier = rand() % 4;
    return lotteryMultiplier * 15;
}

double breakroom::getLottery() {
    return lotteryMultiplier * 15;
}

int breakroom::getInput2() {
    return input2;
}

// location #5 - no SOUTH
space *breakroom::moveSpace(space *currentSpace, int direction) {
    space *newSpace;
    switch (direction - 1) {
    case s:
	   cout << "No store SOUTH of here. Let's go NORTH instead." << endl;
    case n:
	   newSpace = currentSpace->north;
	   break;
    case e:
	   newSpace = currentSpace->east;
	   break;
    case w:
	   newSpace = currentSpace->west;
	   break;
    default:
	   cout << "You ended up staying in the Breakroom." << endl;
	   newSpace = currentSpace;
    }

    return newSpace;
}

/*********************************************************************
** Description: Handle Floats - To input validate choices within a range
*********************************************************************/
double breakroom::validateFloat(double choice, int lowerLimit, int upperLimit) {
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


void breakroom::storeItems() {}
//space *breakroom::moveSpace(space *currentSpace, int direction) {}
void breakroom::viewItems() {}
double breakroom::calculateItemCost() {
    return 0;
}
item breakroom::buyItems() {
    item dummyItem;
    return dummyItem;
}
void breakroom::storeFrontMenu() {}
void breakroom::sales() {}
double breakroom::getItemPrice() {
    return 0;
}