//#include "space.hpp"
//#include "1shoeStore.hpp"
//#include "2clothingStore.hpp"
//#include "3outletStore.hpp"
//#include "4accessoryStore.hpp"
////#include "5dressingRoom.hpp"
//#include "5breakRoom.hpp"
//#include "6beautyStore.hpp"
//#include "player.hpp"

#include "shoppingGameplay.hpp"

int main() {
    gameplay game;
    game.play();
    game.categorizeOutfit();
    game.checkOutfitRequirements();

    //space *s1 = new shoeStore;
    //space *c1 = new clothingStore;
    //space *o1 = new outletStore;
    //space *a1 = new accessoryStore;
    //space *d1 = new dressingRoom;
    //space *b1 = new beautyStore;
    //shoeStore *s1 = new shoeStore;
    //clothingStore *c1 = new clothingStore;
    //outletStore *o1 = new outletStore;
    //accessoryStore *a1 = new accessoryStore;
    //dressingRoom *d1 = new dressingRoom;
    //breakroom *BR = new breakroom;
    //beautyStore *b1 = new beautyStore;

    //
    //s1->north = NULL;  
    //s1->east = c1;
    //s1->south = a1;   
    //s1->west = NULL;

    //c1->north = NULL;
    //c1->east = o1;
    //c1->south = BR; 
    //c1->west = s1;

    //o1->north = NULL;
    //o1->east = NULL;
    //o1->south = b1;   
    //o1->west = c1;

    //a1->north = s1;
    //a1->east = BR;
    //a1->south = NULL;
    //a1->west = NULL;

    //BR->north = c1;
    //BR->east = b1;
    //BR->south = NULL;
    //BR->west = a1;

    //b1->north = o1;
    //b1->east = NULL;    
    //b1->south = NULL;
    //b1->west = BR; 

    //bool gameover = false;
    //int repeat = 1; // 1=true, 0=false
    //player p;
    //p.setMyLocation(s1);
    //while (!gameover) {

	   //cout << p.getMyLocation()->getLocationName() << endl;
	   //s1->storeFrontMenu();
	   //p.purchaseItem(s1);
	   //p.viewOutfit();

	   //cout << endl;
	   //if (p.getMyLocation() == s1) {
		  //s1->storeFrontMenu();
		  //p.purchaseItem(s1);
		  //p.viewOutfit();
	   //}

	   //cout << endl;
	   //if (p.getMyLocation() == c1) {
		  //c1->storeFrontMenu();
		  //p.purchaseItem(c1);
		  //p.viewOutfit();
	   //}

	   //cout << endl;
	   //if (p.getMyLocation() == o1) {
		  //o1->storeFrontMenu();
		  //p.purchaseItem(o1);
		  //p.viewOutfit();
	   //}

	   //cout << endl;
	   //if (p.getMyLocation() == a1) {
		  //a1->storeFrontMenu();
		  //p.purchaseItem(a1);
		  //p.viewOutfit();
	   //}

	   //cout << endl;
	   //if (p.getMyLocation() == b1) {
		  //b1->storeFrontMenu();
		  //p.purchaseItem(b1);	 // move() is called in this function
		  //p.viewOutfit();
	   //}

	   //cout << endl;
	   //if (p.getMyLocation() == BR) {
		  //BR->breakRoomMenu();
		  //if (BR->getInput2() == 1) {
			 //p.setBank(p.getBank() - 5); // $5 cost of lottery
			 //p.setBank(p.getBank() + BR->getLottery());	// add lottery winning amount
			 //p.move();

		  //}
		  //else if (BR->getInput2() == 2) {
			 //p.move();
		  //}
		  //else if (BR->getInput2() == 3) {
			 //gameover = true;
			 //break;
		  //}
	   //}

	   //cout << endl;
	   //cout << "Do you want to continue shopping? Enter 1: ";
	   //cin >> repeat;
    //}

    //
    //cout << endl;
    //cout << p.getMyLocation() << endl;
    //delete b1;
    //delete d1;
    //delete BR;
    //delete a1;
    //delete o1;
    //delete c1;
    //delete s1;
    
  //  system("pause");
    return 0;
}
