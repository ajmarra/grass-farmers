#include "fred.h"
#include "item.h"

Fred::Fred(double x, double y) : Character(ActorType::FRED, x, y, 50, 50, 30, 200, 100) {

}

void Fred::addItem(Item* toAdd) {
	bool notAdded = true;
	int i = 0;

	while (notAdded) {
		if (inventory[i] == nullptr) {
			inventory[i] = toAdd;
			notAdded = false;
		}
		i++;
	}
}

Item* Fred::removeItemAtIndex(int index) {
	Item* toReturn = inventory[index];
	inventory[index] = nullptr;
	return (toReturn);
}

