#include <math.h>
#define PI 3.14159265

#include "actor.h"
#include "bullet.h"

Bullet::Bullet(double x, double y, int size, double speed, double direction, float damage)
    : Actor(ActorType::BULLET, x, y, size, size) {
    this->damage = damage;
    this->xSpeed = speed * cos(direction * (PI / 180));
    this->ySpeed = speed * sin(direction * (PI / 180));
}

void Bullet::update(float delta) {
    Actor::update(delta);
    this->timer -= delta;
}