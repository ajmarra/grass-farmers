#include <SFML/Graphics.hpp>
#include <logic/item.h>
#include <logic/actor.h>

Item::Item(int x, int y, int quantity, bool stackable) {
	this->x = x;
	this->y = y;
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

