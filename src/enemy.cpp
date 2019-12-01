#include "enemy.h"
#include "item.h"

Enemy::Enemy(double x, double y, double mass, double maxSpeed, double maxHealth, int enemyType) :
    Character(ActorType::ENEMY, x, y, 50, 50, mass, maxSpeed, maxHealth) {
    this->enemyType = enemyType;
    
    if (enemyType == 1) {
        this->damageAmount = 2;
    }
    else if (enemyType == 2) {
        this->damageAmount = 7;
    }
    else if (enemyType = 3) {
        this->damageAmount = 10;
    }
}

