#include <SFML/Graphics.hpp>
#include "item.h"
#include "actor.h"

Item::Item(double x, double y, int quantity, bool stackable) {
	this->x = x;
	this->y = y;
    this->quantity = quantity;
    this->stackable = stackable;
}

void Item::increaseQuantity(void) {
	this->quantity += 1;
}

void Item::decreaseQuantity(void) {
	if (this->quantity > 0) {
		this->quantity -= 1;
	}
}

