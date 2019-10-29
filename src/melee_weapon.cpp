#include "item.h"
#include "melee_weapon.h"

MeleeWeapon::MeleeWeapon(double x, double y, int strength, int speed) {
	this->x = x;
	this->y = y;
	this->strength = strength;
	this->speed = speed;
}

void MeleeWeapon::setStrength(int strength) {
	this->strength = strength;
}

void MeleeWeapon::setSpeed(int speed) {
	this->speed = speed;
}

double MeleeWeapon::swingWeapon(void) {

}