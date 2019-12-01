#ifndef CHERYL_H
#define CHERYL_H

#include "actor.h"
#include "item.h"
#include "character.h"
#include "enemy.h"

#include <memory>
#include <list>
#include <iostream>

class Cheryl : public Enemy {

public:
    Cheryl(double x, double y, double mass, double maxSpeed);

    void update(float delta) override;
};

#endif