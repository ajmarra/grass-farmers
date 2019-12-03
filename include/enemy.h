#ifndef ENEMY_H
#define ENEMY_H

#include "actor.h"
#include "item.h"
#include "character.h"

#include <memory>
#include <list>
#include <iostream>

class Enemy : public Character {
private:
    int enemyType;
    double damageAmount;

public:
    Enemy(double x, double y, double mass, double maxSpeed, int enemyType);

    int getEnemyType(void) { return enemyType; };

    void setDamage(double damage) { this->damageAmount = damage; };

    double getDamage(void) { return damageAmount; };

};

#endif