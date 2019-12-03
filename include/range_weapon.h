#ifndef RANGE_H
#define RANGE_H

#include <list>
#include <memory>
#include "music.h"
#include "actor.h"
#include "item.h"
#include "bullet.h"

// The guns that can be dropped by enemies and used by both enemies and Fred
// Have randomized firing rate and damage values
class RangeWeapon : public Item {
    private:
        //scaling factors for damage and time between each hit and type of gun
        float damage;
        
        Sounds pew;

    public:
        RangeWeapon(double x, double y, double width, double height, float damage, float fireRate);

        void setdamage(float damage) { this->damage = damage; };
        
        float getdamage(void) { return this->damage; };

        void use(int x, int y) override;

        void update(float delta) override;

};

#endif