#include "iostream"

#include "actor.h"
#include "item.h"
#include "range_weapon.h"
#include "bullet.h"
#include "room.h"

#include <math.h>
#define PI 3.14159265

RangeWeapon::RangeWeapon(double x, double y, double width, double height, int damage, float fireRate) :
	Item(ActorType::RANGEWEAPON, x, y, width, height, 1, false) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->loadTime = fireRate;
	this->type = type;
}

void RangeWeapon::use(int x, int y) {
	if (!this->reloading) {
		reloading = this->loadTime;
		double direction = atan2(y - this->character->getCenterY(), x - this->character->getCenterX()) * 180 / PI  - 5 + (rand() % 10);
		
		double xOffset = double(this->character->getWidth() / 2 + 20) * cos(direction * PI / 180);
		double yOffset = double(this->character->getHeight() / 2 + 20) * sin(direction * PI / 180);
		this->character->getCurrentRoom()->addActor(
			std::make_shared<Bullet>(this->character->getCenterX() + xOffset,
			this->character->getCenterY() + yOffset, 6, 800, direction, this->damage)
		);
	}
}

void RangeWeapon::update(float delta) {
	this->reloading = this->reloading < 0? 0 : this->reloading - delta;
	Actor::update(delta);
}