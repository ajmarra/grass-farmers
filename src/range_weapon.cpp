#include "item.h"
#include "range_weapon.h"

RangeWeapon::RangeWeapon(double x, double y, double width, double height, int damage, int fireRate) :
	Item(ActorType::WEAPON, x, y, width, height, 1, false) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->fireRate = fireRate;
}

void RangeWeapon::use(int x, int y) {

}