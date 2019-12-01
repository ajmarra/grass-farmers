#include "iostream"

#include "actor.h"
#include "item.h"
#include "range_weapon.h"
#include "bullet.h"
#include "room.h"

#include <math.h>
#define PI 3.14159265

RangeWeapon::RangeWeapon(double x, double y, double width, double height, int damage, int fireRate, std::shared_ptr<Character> character) :
	Item(ActorType::RANGEWEAPON, x, y, width, height, 1, false, character) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->fireRate = fireRate;
	this->type = type;
}

void RangeWeapon::use(int x, int y) {
	if (!this->loading) {
		loading = this->fireRate;
		double direction = atan2(y - this->character->getCenterY(), x - this->character->getCenterX()) * 180 / PI;
		
		this->character->getCurrentRoom()->addActor(
			std::make_shared<Bullet>(this->character->getCenterX(),
			this->character->getCenterY(), 2, 800, direction, this->damage));
	}
}

void RangeWeapon::update(float dt) {
	loading = loading < 0? 0 : loading - dt;
	Actor::update(dt);
}