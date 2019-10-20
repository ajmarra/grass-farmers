#include "math.h"

#include "character.h"
#include "actor.h"

Character::Character(double x, double y, double width, double height, double mass, double topSpeed, int maxHealth)
    : Actor(x, y, width, height) {
    this->mass = mass;
    this->topSpeed = topSpeed;
    this->health =
    this->maxHealth = maxHealth;
}

void Character::damage(int d) {
    health -= d;
    if (health > maxHealth) health = maxHealth;
}

void Character::update(void) {
    Actor::update();

    //put moving code here in the update method (based on the current actual direction/speed, and the desired direction/top speed and acceleration)
}
