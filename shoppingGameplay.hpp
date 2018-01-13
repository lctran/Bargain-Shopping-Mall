//#ifndef SHOPPINGGAMEPLAY_HPP
//#define SHOPPINGGAMEPLAY_HPP

#include "1shoeStore.hpp"
#include "2clothingStore.hpp"
#include "3outletStore.hpp"
#include "4accessoryStore.hpp"
#include "5breakRoom.hpp"
#include "6beautyStore.hpp"
#include "player.hpp"

class gameplay {
public:
    gameplay();
    ~gameplay();

    void play();
    void categorizeOutfit();
    void checkOutfitRequirements();
    bool getOutfitComplete();
    void displayGameIntroduction(); // list game instructions

private:
    bool gameover;
    player p;
    shoeStore *s1;
    clothingStore *c1;;
    outletStore *o1;
    accessoryStore *a1;
    breakroom *BR;
    beautyStore *b1;

    bool shoes, top, bottom, accessory, beautyItem;
    bool outfitComplete;
};

//#endif
