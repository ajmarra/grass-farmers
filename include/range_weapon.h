#ifndef RANGE_H
#define RANGE_H

#include "item.h"

class RangeWeapon : public Item {
private:
	//scaling factors for damage and time between each hit and type of gun
	int strength, fireRate, type;

public:
	RangeWeapon(double x, double y, double width, double height, int strength, int fireRate, int type, std::shared_ptr<Character> fred);

	int getStrength(void) { return strength; };
	int getFireRate(void) { return fireRate; };

	void setStrength(int strength);
	void setFireRate(int fireRate);

	//fires range weapon and returns a double for damage precentage based on strength value
	//The speed value dictates the wait time between each attack
	double fireGun(void);

	//Might not need this if we make ammo continuous?
	//void reloadGun(void);

};

#endif //RANGE_H