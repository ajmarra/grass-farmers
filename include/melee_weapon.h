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
        int damage = 20;
        int speed;
        int loading = true;
        float elapsedTime = 0;
        float reloadRate = 2;
        double distance = 30;

        


    public:
        MeleeWeapon(double x, double y, double width, double height, int damage, int speed, std::shared_ptr<Character> character);

        void setDamage(int damage) { this->damage = damage; };
        
        int getDamage(void) { return damage; };

        void setSpeed(int speed) { this->speed = speed; };

        int getSpeed(void) { return speed; };

        void use(int x, int y) override;

        void update(float delta) override;
};

#endif