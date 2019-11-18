#include "item.h"
#include "health_item.h"

HealthItem::HealthItem(double x, double y, double width, double height) :
	Item(ActorType::HEALTH, x, y, width, height, 1, true) {
	this->x = x;
	this->y = y;

}

