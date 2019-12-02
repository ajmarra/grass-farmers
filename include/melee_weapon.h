#ifndef MELEE_H
#define MELEE_H

#include <list>
#include <memory>

#include "room.h"
#include "actor.h"
#include "item.h"

class MeleeWeapon : public Item {
    private:
        // range of weapon
        double damage;
	    int range = 100;
        Sounds swoosh;

    public:
        MeleeWeapon(double x, double y, double width, double height, int damage, int speed);

        void setDamage(int damage) { this->damage = damage; };
        
        int getDamage(void) { return damage; };

        void use(int x, int y) override;

        void update(float delta) override;

};

#endif