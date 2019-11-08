#ifndef MELEE_H
#define MELEE_H

#include "item.h"

class MeleeWeapon : public Item {
private:
	//scaling factors for damage and time between each hit
	int strength, speed;

public:
	MeleeWeapon(double x, double y, double height, double width, int strength, int speed);

	int getStrength(void) { return strength; };
	int getSpeed(void) { return speed; };

	void setStrength(int strength);
	void setSpeed(int speed);

	//swings melee weapon and returns a double for damage precentage based on strength value
	//The speed value dictates the wait time between each attack
	double swingWeapon(void);

};

#endif //MELEE_H