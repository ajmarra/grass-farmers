#include "item.h"
#include "range_weapon.h"

RangeWeapon::RangeWeapon(double x, double y, int strength, int fireRate, int type) {
	this->x = x;
	this->y = y;
	this->strength = strength;
	this->fireRate = fireRate;
	this->type = type;
}

void RangeWeapon::setStrength(int strength) {
	this->strength = strength;
}

void RangeWeapon::setfireRate(int fireRate) {
	this->fireRate = fireRate;
}

double RangeWeapon::attack(void) {

}