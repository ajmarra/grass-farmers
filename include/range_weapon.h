#ifndef RANGE_H
#define RANGE_H

#include "item.h"

class RangeWeapon : public Item {
private:
	//scaling factors for damage and time between each hit and type of gun
	int strength, fireRate, type;

public:
	RangeWeapon(double x, double y, int strength, int fireRate, int type);

	int getStrength(void) { return strength; };
	int getFireRate(void) { return fireRate; };

	void setStrength(int strength);
	void setFireRate(int fireRate);

	//fires range weapon and returns a double for damage precentage based on strength value
	//The speed value dictates the wait time between each attack
	double fireGun(void);

};

#endif RANGE_H