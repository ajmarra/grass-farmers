#include "item.h"
#include "melee_weapon.h"

MeleeWeapon::MeleeWeapon(double x, double y, double width, double height, int strength, int speed) : 
	Item(ActorType::WEAPON,x, y, width, height, 1, false) {
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