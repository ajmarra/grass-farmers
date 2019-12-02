#ifndef BULLET_H
#define BULLET_H

#include "actor.h"

class Bullet : public Actor {
    protected:
        int damage;
        float timer = 5;
    public:
        Bullet(double x, double y, int size, double speed, double direction, int damage);

        int getTimer(void) { return this->timer; };

        int getDamage(void) { return this->damage; };

        void update(float delta) override;
};

#endif