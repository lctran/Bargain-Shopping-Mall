#include "space.hpp"

space::space() {
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
}

space::~space() {
    //myCloset.clear();

}

string space::getLocationName() {
    return this->locationName;
}

void space::spaceMenu() {
    cout << "Select one of the following options:  " << endl;
    cout << "--------------------------------------" << endl;
    cout << " 1 - shop " << endl;
    cout << " 2 - got to another store " << endl;
    cout << "--------------------------------------" << endl;
    cout << " CHOICE:  ";
    cin >> choice;
    choice = validateFloat(choice, 1, 2);	// input validation, change the number of choices
}

//void space::movePrompt() {
//    cout << "Which direction would you like to go? " << endl;
//    cout << "Select one of the following options:  " << endl;
//    cout << "--------------------------------------" << endl;
//    cout << " 1 - north " << endl;
//    cout << " 2 - east " << endl;
//    cout << " 3 - south " << endl;
//    cout << " 4 - west " << endl;
//    cout << "--------------------------------------" << endl;
//    cout << " CHOICE:  ";
//    cin >> choiceDir;
//    choiceDir = validateFloat(choiceDir, 1, 4);	// input validation, change the number of choices
//}

double space::getChoiceDir() {
    return choiceDir;
}

double space::getChoice() {
    return choice;
}

void space::viewCloset() {
    cout << " Items in Closet " << endl;
    cout << "-----------------" << endl;
    int tempVal = myCloset.size(); // fix C4018
    for (int i = 0; i < tempVal; i++)
	   cout << i + 1 << " - " << myCloset[i].itemName << "  $" << myCloset[i].price << endl;
    cout << "-----------------" << endl;
}
/*********************************************************************
** Description: Handle Floats - To input validate choices within a range
*********************************************************************/
double space::validateFloat(double choice, int lowerLimit, int upperLimit) {
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