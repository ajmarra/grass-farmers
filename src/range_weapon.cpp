#include "actor.h"
#include "item.h"
#include "range_weapon.h"
#include "bullet.h"

#include <math.h>
#define PI 3.14159265

RangeWeapon::RangeWeapon(std::shared_ptr<MasterLogic> &logic, double x, double y, double width, double height, int damage, int fireRate) :
	Item(ActorType::WEAPON, x, y, width, height, 1, false) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->fireRate = fireRate;
}

void RangeWeapon::use(int x, int y) {
	double direction = atan2(y - this->y, x - this->x) * 180 / PI;
	this->logic->getActorList().emplace_back(std::make_shared<Bullet>(this->x, this->y, 2, 4, direction, this->damage));
}