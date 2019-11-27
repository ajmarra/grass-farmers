#include "item.h"
#include "health_item.h"
#include "character.h"

HealthItem::HealthItem(double x, double y, double width, double height, std::shared_ptr<Character> fred) :
	Item(ActorType::HEALTH, x, y, width, height, 1, true, fred) {
	this->x = x;
	this->y = y;
}

void HealthItem::use(int x, int y) {
    this->getCharacter()->heal(healQuantity);
}