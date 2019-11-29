#include "iostream"

#include "actor.h"
#include "item.h"
#include "range_weapon.h"
#include "bullet.h"
#include "room.h"

#include <math.h>
#define PI 3.14159265

RangeWeapon::RangeWeapon(double x, double y, double width, double height, int damage, int fireRate, std::shared_ptr<Character> character) :
	Item(ActorType::WEAPON, x, y, width, height, 1, false, character) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->fireRate = fireRate;
	this->type = type;
}

void RangeWeapon::use(int x, int y) {
    double direction = atan2(y - this->y, x - this->x) * 180 / PI;
	std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(this->character->getX(), this->character->getY(), 2, 800, direction, this->damage);
    this->character->getCurrentRoom()->addActor(bullet);
}