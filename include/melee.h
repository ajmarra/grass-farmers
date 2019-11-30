#ifndef MELEE_H
#define MELEE_H

#include <list>
#include <memory>

#include "room.h"
#include "actor.h"
#include "item.h"

class MeleeWeapon : public Item {
    private:
        //scaling factors for damage and time between each hit and type of gun
        int damage, fireRate, type;

    public:
        MeleeWeapon(double x, double y, double width, double height, int damage, std::shared_ptr<Character> character);

        void setdamage(int damage) { this->damage = damage; };
        
        int getdamage(void) { return damage; };

        void use(int x, int y) override;
};

#endif