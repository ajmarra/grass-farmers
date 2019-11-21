#ifndef ENEMY_H
#define ENEMY_H

#include "actor.h"
#include "character.h"

#include <memory>
#include <list>
#include <iostream>

class Enemy : public Character {

public:
    Enemy(double x, double y, double mass, double maxSpeed, double maxHealth);

};

#endif