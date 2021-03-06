#include "item.h"
#include "health_item.h"
#include "character.h"

HealthItem::HealthItem(double x, double y, double width, double height) :
	Item(ActorType::HEALTH, x, y, width, height, 1, true) {
	this->x = x;
	this->y = y;
}

void HealthItem::use(int x, int y) {
    this->getCharacter()->heal(healQuantity);
    this->decreaseQuantity();
    if (this->getQuantity() < 1) {
        this->setUsedItem(true);
        this->getCharacter()->popItemAtIndex(this->getCharacter()->getSelectedIndex());
    }
}