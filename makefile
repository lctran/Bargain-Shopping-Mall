all:
	g++ mainFP2.cpp player.cpp space.cpp 1shoeStore.cpp 2clothingStore.cpp 3outletStore.cpp 4accessoryStore.cpp 5breakRoom.cpp 6beautyStore.cpp shoppingGameplay.cpp -o test

clean:
	rm test
