#include "iostream"

#include "actor.h"
#include "item.h"
#include "melee_weapon.h"
#include "room.h"
#include "enemy_view.h"

#include <math.h>
#define PI 3.14159265

MeleeWeapon::MeleeWeapon(double x, double y, double width, double height, int damage, int speed, std::shared_ptr<Character> character) :
    Item(ActorType::MELEEWEAPON, x, y, width, height, 1, false, character) {
    this->x = x;
    this->y = y;
    this->damage = damage;
    this->speed = speed;
    this->loadTime = 1;
}

void MeleeWeapon::use(int x, int y) {
    if (!this->reloading) {
		reloading = this->loadTime;
        double abso = 70;
        this->inUse = true;

        double direction = atan2(y - this->character->getCurrentRoom()->getFred()->getCenterY(), x - this->character->getCurrentRoom()->getFred()->getCenterX())*180/PI;

        if (this->character->getCurrentRoom()->getEnemyList().size() > 0) {
            for (std::shared_ptr<Enemy> enemy : this->character->getCurrentRoom()->getEnemyList()) {
                //up sweep
                if (direction >= -135.0 && direction < -45.0) {
                    if ((enemy->getCenterY() < this->character->getCurrentRoom()->getFred()->getCenterY())) {
                        if (abs(enemy->getCenterY() - this->character->getCurrentRoom()->getFred()->getCenterY()) <= abso) {
                            enemy->damage(this->damage);
                        }
                    }
                }

                //left sweep
                else if ((direction < -135.0 && direction >= -180.0 ) || ( direction <= 180.0 && direction > 135.0)) {
                    if (enemy->getCenterX() < this->character->getCurrentRoom()->getFred()->getCenterX()){
                        if (abs((enemy->getCenterX() - this->character->getCurrentRoom()->getFred()->getCenterX())) <= abso) {
                            enemy->damage(this->damage);
                        }
                    }
                }

                //down sweep
                else if (direction <= 135.0 && direction > 45.0) {
                    if (enemy->getCenterY() > this->character->getCurrentRoom()->getFred()->getCenterY()){
                        if (abs( enemy->getCenterY() - this->character->getCurrentRoom()->getFred()->getCenterY()) <= abso){
                            enemy->damage(this->damage);
                        }
                    }
                }

                //right sweep
                else if ((direction < 45.0 && direction > 0.0) || (direction >= -45.0 && direction < 0.0)){
                    if (enemy->getCenterX() > this->character->getCurrentRoom()->getFred()->getCenterX()){
                        if (abs(enemy->getCenterX() - this->character->getCurrentRoom()->getFred()->getCenterX()) <= abso) {
                            enemy->damage(this->damage);
                        }
                    }
                }

                //Damage if alien is hitting fred
                if (enemy->collidesSquare(*this->character->getCurrentRoom()->getFred())) enemy->damage(this->damage);
            }
        }
    }
}

void MeleeWeapon::update(float delta) {
    this->reloading = this->reloading < 0? 0 : this->reloading - delta;
	Actor::update(delta);
}