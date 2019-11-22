#ifndef TRAP_H
#define TRAP_H

#include "item.h"

/*
* Trap items take time to set and then do a lot of damage to the enemy that step on them.
* They do not damage fred when he walks over them.
*/
class Trap : public Item {
private:
    int damage = 100;
    float elapsedTime = 0;
    float delta;
    bool isSet = false;

public:
    Trap(double x, double y, double width, double height);

    bool getIsSet(void) { return isSet; };

    int getDamage(void) { return damage; };

    /*
    * Sets the trap
    */
    void use(int x, int y) override;

    void update(float delta) override;

};

#endif //Trap_H