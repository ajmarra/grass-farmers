#include "item.h"
#include "range_weapon.h"

RangeWeapon::RangeWeapon(double x, double y, double width, double height, int strength, int fireRate, int type, std::shared_ptr<Character> fred) :
	Item(ActorType::WEAPON, x, y, width, height, 1, false, fred) {
	this->x = x;
	this->y = y;
	this->strength = strength;
	this->fireRate = fireRate;
	this->type = type;
}

void RangeWeapon::setStrength(int strength) {
	this->strength = strength;
}

void RangeWeapon::setFireRate(int fireRate) {
	this->fireRate = fireRate;
}

double RangeWeapon::fireGun(void) {

}