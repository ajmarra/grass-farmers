#ifndef BULLET_H
#define BULLET_H

#include "actor.h"

class Bullet : public Actor {
    protected:
        int damage;
    public:
        Bullet(double x, double y, int size, double speed, double direction, int damage);

        int getDamage(void) { return this->damage; };

        void update(float dt) override;
};

#endif