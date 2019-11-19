#include "fred.h"
#include "item.h"
#include <iostream>
#include <list>

Fred::Fred(double x, double y) : Character(ActorType::FRED, x, y, 64, 64, 10, 200, 100) {

}

void Fred::addItem(std::list<std::shared_ptr<Item>> itemList) {
	bool notAdded = true;
	int i = 0;
	std::shared_ptr<Item> toAdd;
	for (std::list<std::shared_ptr<Item>>::iterator it = itemList.begin(); it != itemList.end(); ++it) {
		if (this->collidesSquare(*(*it))) {
			toAdd = (*it);
			i = 0;
			while (notAdded) {
				if (i == 4) notAdded = false;
				else if (inventory[i] == nullptr) {
					inventory[i] = toAdd;
					notAdded = false;
					if (i == 0) toAdd->setXY(825, 40);
					else if (i == 1) toAdd->setXY(925, 40);
					else if (i == 2) toAdd->setXY(1025, 40);
					else if (i == 3) toAdd->setXY(1125, 40);
				}
				else if (toAdd->isStackable() && inventory[i]->getType() == this->getType()) {
					inventory[i]->increaseQuantity();
					// need to figure out what to do with old/used items.
				}
				i++;
			}

			break;
		}
	}
	
}
