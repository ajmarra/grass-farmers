#include "item.h"
#include "melee_weapon.h"

MeleeWeapon::MeleeWeapon(double x, double y, double width, double height, int damage, int speed, std::shared_ptr<Character> character) :
	Item(ActorType::WEAPON,x, y, width, height, 1, false, character) {
	this->x = x;
	this->y = y;
	this->damage = damage;
	this->speed = speed;
}

void MeleeWeapon::use(int x, int y) {
    //move the weapon forward in the direction of the coordinates given and set to check for damaging collisions.
}