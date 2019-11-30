#include <memory>
#include <iostream>
#include <list>

#include "math.h"
#define PI 3.14159265

#include "actor.h"
#include "item.h"
#include "room.h"
#include "character.h"

Character::Character(ActorType type, double x, double y, double width, double height, double mass, double maxSpeed, int maxHealth)
    : Actor(type, x, y, width, height) {
    this->mass = mass;
    this->maxSpeed = maxSpeed;
    this->health =
    this->maxHealth = maxHealth;
}

void Character::damage(int d) {
    health -= d;
    if (health > maxHealth) health = maxHealth;
}

void Character::heal(int healAmount) {
    health += healAmount;
    if (health > maxHealth) health = maxHealth;
}

void Character::move(void) {
    if (this->desiredDirection >= 0) {
        this->xSpeed += (10.0 / this->mass) * cos(this->desiredDirection * (PI / 180));
        this->ySpeed += (10.0 / this->mass) * sin(this->desiredDirection * (PI / 180));

        if (this->getSpeed() > this->maxSpeed) {
            this->xSpeed = maxSpeed * cos(this->getDirection() * (PI / 180));
            this->ySpeed = maxSpeed * sin(this->getDirection() * (PI / 180));
        }
        return;
    }

    if (fabs(this->ySpeed) >= 10.0 / this->mass) {
        this->ySpeed -= (10.0 / this->mass) * sin(this->getDirection() * PI / 180);
    }
    else ySpeed = 0;

    if (fabs(this->xSpeed) >= 10.0 / this->mass) {
        this->xSpeed -= (10.0 / this->mass) * cos(this->getDirection() * PI / 180);
    }
    else xSpeed = 0;
}

void Character::update(float delta) {
    Actor::update(delta);
    if (this->canMove && sleepTime <= 0) {
        Character::move();
    }
    else {
        this->hardStop();
        sleepTime -= delta;
    }
}

void Character::addItem(void) {
    for (std::shared_ptr<Item> item : this->curRoom->getItemList()) {
        if (this->collidesSquare(*item) && item->getCanPickUp()) {
            this->curRoom->removeActor(item);
            if (item->isStackable()) {
                for (std::shared_ptr<Item> &slot : this->inventory) {
                    if (slot && item->getType() == slot->getType()) {
                        slot->increaseQuantity();
                        return;
                    }
                }
            }
            for (std::shared_ptr<Item> &slot : this->inventory) {
                if (!slot) {
                    slot = item;
                    return;
                }
            }


            /**
            for (std::shared_ptr<Item> &item : this->inventory) {
                if (item->isStackable() && inventory[i] != nullptr && inventory[i]->getType() == item->getType()) {
                    inventory[i]->increaseQuantity();
                    item->setUsedItem(true);
                    //item->setXY(inventory[i]->getCenterX()-10, inventory[i]->getCenterY()-10);
                    findSlot = false;
                }
                else if (i == 4) findSlot = false;
                else if (inventory[i] == nullptr) {
                    inventory[i] = item;
                    findSlot = false;
                    if (i == 0) {
                        item->setPos(825, 40);
                    }
                    else if (i == 1) {
                        item->setPos(925, 40);
                    }
                    else if (i == 2) {
                        item->setPos(1025, 40);
                    }
                    else if (i == 3) {
                        item->setPos(1125, 40);
                    }
                    if (selectedIndex == i) this->setSelectedIndex(i);
                }
                i++;
            }
            break;
            */
        }
    }
}

std::shared_ptr<Item> Character::popItemAtIndex(int index) {
    std::shared_ptr<Item> toReturn = inventory[index];
    inventory[index] = nullptr;
    return (toReturn);
}

void Character::dropItem() {
    std::shared_ptr<Item> toDrop = this->popItemAtIndex(selectedIndex);
    if (toDrop == nullptr) return;
    toDrop->setPos(this->getCenterX(), this->getCenterY());
    this->getCurrentRoom()->addActor(toDrop);
}