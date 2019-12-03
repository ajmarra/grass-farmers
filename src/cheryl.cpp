#include "enemy.h"
#include "cheryl.h"

Cheryl::Cheryl(double x, double y, double mass, double maxSpeed) :
    Enemy(x, y, mass, maxSpeed, 400, 4) {
    this->setWidthHeight(100, 100);
    this->setType(ActorType::CHERYL);
}

void Cheryl::update(float delta) {
    if (this->getHealth() <= 100) {
        this->setMaxSpeed(220);
        this->setMass(10);
        this->setDamage(20);
    }
    else if (this->getHealth() <= 200) {
        this->setMaxSpeed(200);
        this->setMass(20);
        this->setDamage(15);
    }
    else if (this->getHealth() <= 300) {
        this->setMaxSpeed(140);
        this->setMass(30);
        this->setDamage(12);
    }
    Character::update(delta);
}

void Cheryl::damage(float d) {
    Character::damage(d);
    cherylDamageSound.playCherylDamageSound();
}