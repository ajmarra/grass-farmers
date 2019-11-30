#include "enemy.h"
#include "cheryl.h"

Cheryl::Cheryl(double x, double y, double mass, double maxSpeed) :
    Enemy(x, y, mass, maxSpeed, 400) {
    this->setWidthHeight(100, 100);
    this->setType(ActorType::CHERYL);
}

