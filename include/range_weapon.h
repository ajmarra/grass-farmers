#ifndef RANGE_H
#define RANGE_H

#include <list>
#include <memory>

#include "room.h"
#include "actor.h"
#include "item.h"
#include "bullet.h"

class RangeWeapon : public Item {
    private:
        //scaling factors for damage and time between each hit and type of gun
        int damage, fireRate, type;

    public:
        RangeWeapon(double x, double y, double width, double height, int damage, int fireRate, std::shared_ptr<Character> character);

        int getStrength(void) { return damage; };

        void setdamage(int damage) { this->damage = damage; };
        
        int getdamage(void) { return damage; };

        void setFireRate(int fireRate) { this->fireRate = fireRate; };
        
        int getFireRate(void) { return fireRate; };

        void use(int x, int y) override;
};

#endif