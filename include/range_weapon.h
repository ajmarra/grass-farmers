#ifndef RANGE_H
#define RANGE_H

#include <list>
#include <memory>
#include "music.h"
#include "actor.h"
#include "item.h"
#include "bullet.h"

class RangeWeapon : public Item {
    private:
        //scaling factors for damage and time between each hit and type of gun
        int damage;
        
        Sounds pew;

    public:
        RangeWeapon(double x, double y, double width, double height, int damage, float fireRate);

        int getStrength(void) { return damage; };

        void setdamage(int damage) { this->damage = damage; };
        
        int getdamage(void) { return damage; };

        void use(int x, int y) override;

        void update(float delta) override;

};

#endif