
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "space.hpp"


class player {
public:
    player();			   // default constructor
    ~player();			   // destructor

    double getBank();
    void setBank(double);

    void setMyLocation(space *newSpace);
    space *getMyLocation();

    void purchaseItem(space *store);
    void viewOutfit();
    void move();
    int getOutfitVectorSize();


    item getOutfitItems(int position);
    double validateFloat(double, int, int);

private:
    vector<item> outfit;
    space *currentSpace;

    double bank;
    int closetSize;

    double userInput;
    int switchChoice;

};

#endif