#include <SFML/Graphics.hpp>
#include "item.h"
#include "actor.h"

Item::Item(ActorType type, double x, double y, double width, double height, int quantity, bool stackable) :
    Actor(type, x, y, width, height) {
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