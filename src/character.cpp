#include "actor.h"
#include "character.h"

Character::Character(ActorType type, double x, double y, double width, double height, double mass, double topSpeed, int maxHealth)
    : Actor(type, x, y, width, height) {
    this->mass = mass;
    this->topSpeed = topSpeed;
    this->health =
    this->maxHealth = maxHealth;
}

void Character::damage(int d) {
    health -= d;
    if (health > maxHealth) health = maxHealth;
}

void Character::update(float delta) {
    Actor::update(delta);

    if (this->desiredDirection >= 0) {
        double newXSpeed = this->getXSpeed() + ((100 / mass)
            * cos(this->desiredDirection * (PI / 180)));
        double newYSpeed = this->getYSpeed() + ((100 / mass)
            * sin(this->desiredDirection * (PI / 180)));
        this->speed = sqrt(pow(newXSpeed, 2) + pow(newYSpeed, 2));
        this->direction = atan(newYSpeed / newXSpeed) * 180 / PI;

        if (this->speed > this->topSpeed) this->speed = this->topSpeed;
    }
    else {
        speed -= 100 / mass;
    }
}
