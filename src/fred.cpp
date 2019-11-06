#include "fred.h"
#include "item.h"
#include <iostream>
#include <list>

Fred::Fred(double x, double y) : Character(ActorType::FRED, x, y, 50, 50, 10, 200, 100) {

}

void Fred::addItem(std::list<std::shared_ptr<Item>> itemList) {
	bool notAdded = true;
	int i = 0;
	std::shared_ptr<Item> toAdd;

	for (std::list<std::shared_ptr<Item>>::iterator it = itemList.begin(); it != itemList.end(); it++) {
		if (this->collides(*(*it))) {
			toAdd = (*it);
			break;
		}
	}
	
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

