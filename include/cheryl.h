#ifndef CHERYL_H
#define CHERYL_H

#include "actor.h"
#include "item.h"
#include "character.h"
#include "enemy.h"
#include "music.h"

#include <memory>
#include <list>
#include <iostream>

/*
* The boss on the final night
*/
class Cheryl : public Enemy {
    private:
        Sounds cherylDamageSound;
        

public:
    Cheryl(double x, double y, double mass, double maxSpeed);

    void update(float delta) override;

    void damage(int d) override;
};

#endif