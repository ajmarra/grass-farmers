#ifndef RANGE_H
#define RANGE_H

#include <list>
#include <memory>
#include "music.h"
#include "actor.h"
#include "item.h"
#include "bullet.h"

/**
 * Gun item, can be used by all characters
 */
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