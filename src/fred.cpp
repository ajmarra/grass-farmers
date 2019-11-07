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

	for (std::list<std::shared_ptr<Item>>::iterator it = itemList.begin(); it != itemList.end(); ++it) {
		if (this->collides(*(*it))) {
			toAdd = (*it);

			while (notAdded) {
				if (inventory[i] == NULL) {
					inventory[i] = toAdd;
					notAdded = false;
					if(i == 0) toAdd->setXY(825, 50);
					else if (i == 1) toAdd->setXY(925, 50);
					else if (i == 2) toAdd->setXY(1025, 50);
					else if (i == 3) toAdd->setXY(1125, 50);
				}
				i++;
			}

			break;
		}
	}
	
}

std::shared_ptr<Item> Fred::removeItemAtIndex(int index) {
	std::shared_ptr<Item> toReturn = inventory[index];
	inventory[index] = nullptr;
	return (toReturn);
}

