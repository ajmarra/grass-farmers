#include "enemy.h"
#include "item.h"

Enemy::Enemy(double x, double y, double mass, double maxSpeed, int enemyType) :
    Character(ActorType::ENEMY, x, y, 50, 50, mass, maxSpeed, 10) {
    this->enemyType = enemyType;
    
    if (enemyType == 1) {
        this->damageAmount = 2;
        this->maxHealth = 10;
        this->health = maxHealth;
    }
    else if (enemyType == 2) {
        this->damageAmount = 7;
        this->maxHealth = 20;
        this->health = maxHealth;
    }
    else if (enemyType >= 3) {
        this->damageAmount = 10;
        this->maxHealth = 30;
        this->health = maxHealth;

    }
}