#ifndef MELEE_H
#define MELEE_H

#include "item.h"

class MeleeWeapon : public Item {
private:
	//scaling factors for damage and time between each hit
	int damage, speed;

public:
	MeleeWeapon(double x, double y, double height, double width, int damage, int speed);

	void setDamage(int damage) { this->damage = damage; };
	
	int getDamage(void) { return damage; };
	
	void setSpeed(int speed) { this->speed = speed; };

	int getSpeed(void) { return speed; };
	
	void use(int x, int y) override;

};

#endif //MELEE_H