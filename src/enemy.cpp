#include "enemy.h"
#include "item.h"

Enemy::Enemy(double x, double y, double mass, double maxSpeed, double maxHealth) : 
    Character(ActorType::ENEMY, x, y, 50, 50, mass, maxSpeed, maxHealth) {

}

