#include "iostream"

#include "actor.h"
#include "item.h"
#include "melee.h"


#include <math.h>
#define PI 3.14159265

MeleeWeapon::MeleeWeapon(double x, double y, double width, double height, int damage, std::shared_ptr<Character> character) :
	Item(ActorType::WEAPON, x, y, width, height, 1, false, character) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->type = type;
}

void MeleeWeapon::use(int x, int y) {
    double direction = atan2(y - this->y, x - this->x) * 180 / PI;
}