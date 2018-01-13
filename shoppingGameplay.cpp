#include "shoppingGameplay.hpp"

// default constructor - create obj spaces and set points between spaces
gameplay::gameplay() {
    gameover = false;

    s1 = new shoeStore;
    c1 = new clothingStore;
    o1 = new outletStore;
    a1 = new accessoryStore;
    BR = new breakroom;
    b1 = new beautyStore;

    s1->north = NULL;
    s1->east = c1;
    s1->south = a1;
    s1->west = NULL;

    c1->north = NULL;
    c1->east = o1;
    c1->south = BR;
    c1->west = s1;

    o1->north = NULL;
    o1->east = NULL;
    o1->south = b1;
    o1->west = c1;

    a1->north = s1;
    a1->east = BR;
    a1->south = NULL;
    a1->west = NULL;

    BR->north = c1;
    BR->east = b1;
    BR->south = NULL;
    BR->west = a1;

    b1->north = o1;
    b1->east = NULL;
    b1->south = NULL;
    b1->west = BR;
}

// destructor
gameplay::~gameplay() {
    delete b1;
    delete BR;
    delete a1;
    delete o1;
    delete c1;
    delete s1;
}

void gameplay::play() {
    p.setMyLocation(s1);
    displayGameIntroduction();  // display game introduction/instructions

    while (!gameover) {
	   if (p.getMyLocation() == s1) {
		  s1->storeFrontMenu();
		  p.purchaseItem(s1);
		  p.viewOutfit();
	   }

	   cout << endl;
	   if (p.getMyLocation() == c1) {
		  c1->storeFrontMenu();
		  p.purchaseItem(c1);
		  p.viewOutfit();
	   }

	   cout << endl;
	   if (p.getMyLocation() == o1) {
		  o1->storeFrontMenu();
		  p.purchaseItem(o1);
		  p.viewOutfit();
	   }

	   cout << endl;
	   if (p.getMyLocation() == a1) {
		  a1->storeFrontMenu();
		  p.purchaseItem(a1);
		  p.viewOutfit();
	   }

	   cout << endl;
	   if (p.getMyLocation() == b1) {
		  b1->storeFrontMenu();
		  p.purchaseItem(b1);	 // move() is called in this function
		  p.viewOutfit();
	   }

	   cout << endl;
	   if (p.getMyLocation() == BR) {
		  BR->breakRoomMenu();
		  if (BR->getInput2() == 1) {
			 p.setBank(p.getBank() - 5); // $5 cost of lottery
			 p.setBank(p.getBank() + BR->getLottery());	// add lottery winning amount
			 p.move();
		  }
		  else if (BR->getInput2() == 2) {
			 p.move();
		  }
		  else if (BR->getInput2() == 3) {
			 gameover = true;
			 break;
		  }
	   }

	   if (p.getOutfitVectorSize() == 5)
		  gameover = true;

	   if (p.getBank() <= 0)
		  gameover = true;
    }
}

void gameplay::categorizeOutfit() {
    cout << endl;
    cout << " Your Final Outfit + Total Spent " << endl;
    cout << "------------------------------------------------" << endl;
    for (int i = 0; i < p.getOutfitVectorSize(); i++) {
	   cout << " --> [" << p.getOutfitItems(i).type << "] " << p.getOutfitItems(i).itemName << " $" << p.getOutfitItems(i).price << endl;

	   if (p.getOutfitItems(i).type == "shoes")
		  shoes = true;
	   else if (p.getOutfitItems(i).type == "tops")
		  top = true;
	   else if (p.getOutfitItems(i).type == "bottoms")
		  bottom = true;
	   else if (p.getOutfitItems(i).type == "accessories")
		  accessory = true;
	   else if (p.getOutfitItems(i).type == "beauty")
		  beautyItem = true;
    }
    cout << "------------------------------------------------" << endl;
}

void gameplay::checkOutfitRequirements() {
    cout << endl;
    cout << " OUTFIT CHECKER " << endl;
    cout << "-----------------------------" << endl;
    if (shoes == false)
	   cout << "Shoe Requirement:  FAILED" << endl;
    else
	   cout << "Shoe Requirement:  MET" << endl;

    if (top == false)
	   cout << "Top Requirement:  FAILED" << endl;
    else
	   cout << "Top Requirement:  MET" << endl;

    if (bottom == false)
	   cout << "Bottom Requirement:  FAILED" << endl;
    else
	   cout << "Bottom Requirement:  MET" << endl;

    if (accessory == false)
	   cout << "Accessory Requirement:  FAILED" << endl;
    else
	   cout << "Accessory Requirement:  MET" << endl;

    if (beautyItem == false)
	   cout << "Beauty Requirement:  FAILED" << endl;
    else
	   cout << "Beauty Requirement:  MET" << endl;
    cout << "-----------------------------" << endl;

    // the final check
    if (shoes == true && top == true && bottom == true && accessory == true && beautyItem == true) {
	   outfitComplete = true;
	   cout << "You successfully shopped for a complete outfit under your specific budget!" << endl;
    }
    else {
	   outfitComplete = false;
	   cout << "The following requirements not met are listed above." << endl;
	   cout << "[FAILED] You did not complete the challenge." << endl;
    }
}

bool gameplay::getOutfitComplete() {
    return outfitComplete;
}

void gameplay::displayGameIntroduction() {
    cout << "*************************************" << endl;
    cout << "     WELCOME TO THE BARGAIN MALL     " << endl;
    cout << "*************************************" << endl;
    cout << "Here is the jist of this challenge:  " << endl;
    cout << " --> To win, complete an outfit before cash and closet space runs out." << endl;
    cout << " --> A complete outfit contains a pair of shoes, top, bottom, accessory, and beauty product." << endl;
    cout << " --> Each store has a different sale each visit. [discounted items]" << endl;
    cout << " --> Closet Size = 5" << endl;
    cout << " --> Initial Bank Balance = $200 [starting cash]" << endl;
    cout << " --> Chance to win cash with a $5 scratch ticket in \"Breakroom\"." << endl;
    cout << " --> A variety of items can be bought at 5 different stores." << endl;
    cout << " --> When done shopping [collecting items], go to \"Breakroom\" to exit mall and check if challenge is completed." << endl;
    cout << " --> Starting Store:  1 Shoes " << endl;
    cout << endl;
    cout << "  MALL DIRECTORY  " << endl;
    cout << "  ___________________________________  " << endl;
    cout << "  |     1     |     2     |    3    |  " << endl;
    cout << "  |   Shoes   |  Clothing |  Outlet |  " << endl;
    cout << "  |___________|___________|_________|  " << endl;
    cout << "  |     4     |     5     |    6    |  " << endl;
    cout << "  | Accessory | Breakroom |  Beauty |  " << endl;
    cout << "  |___________|___________|_________|  " << endl;
    cout << endl;
}