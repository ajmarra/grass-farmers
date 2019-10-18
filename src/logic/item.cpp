#include <SFML/Graphics.hpp>
#include "logic/item.h"

Item::Item(int quantity, bool stackable) {
    this->quantity = quantity;
    this->stackable = stackable;
}

bool Item::isStackable(void) {
	return(this->stackable);
}

int Item::getQuantity(void) {
	return(this->quantity);
}

void Item::increaseQuantity(void) {
	this->quantity += 1;
}

void Item::decreaseQuantity(void) {
	if (this->quantity > 0) {
		this->quantity -= 1;
	}
}