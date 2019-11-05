#include "fred.h"
#include "item.h"
#include <iostream>

Fred::Fred(double x, double y) : Character(ActorType::FRED, x, y, 50, 50, 10, 200, 100) {

}

void Fred::addItem(std::shared_ptr<Item> &toAdd) {
	bool notAdded = true;
	int i = 0;

	while (notAdded) {
		if (inventory[i] == nullptr) {
			inventory[i] = toAdd;
			notAdded = false;
			toAdd->setXY(700, 10);
		}
		i++;
	}
}

std::shared_ptr<Item> Fred::removeItemAtIndex(int index) {
	std::shared_ptr<Item> toReturn = inventory[index];
	inventory[index] = nullptr;
	return (toReturn);
}

