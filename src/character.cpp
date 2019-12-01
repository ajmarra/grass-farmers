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

void Character::heal(int healAmount, float delta) {
    curDelta += delta;
    if (curDelta >= deltaLimit) {
        health += healAmount;
        curDelta = 0;
        
        if (health > maxHealth) health = maxHealth;
    }
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

    //update items in inventory
    for (std::shared_ptr<Item> &slot : this->inventory) {
        if (slot) {
            slot->update(delta);
        }
    }
}

void Character::addItem(void) {
    for (std::shared_ptr<Item> item : this->curRoom->getItemList()) {
        if (this->collidesSquare(*item) && item->getCanPickUp()) {
            this->curRoom->removeActor(item); // remove from room
            item->setCharacter(this->shared_from_this()); // set owned by this character

            // if stackable, increment
            if (item->isStackable()) {
                for (std::shared_ptr<Item> &slot : this->inventory) {
                    if (slot && item->getType() == slot->getType()) {
                        slot->increaseQuantity();
                        return;
                    }
                }
            }

            // add to next empty slot
            int i = 0;
            for (std::shared_ptr<Item> &slot : this->inventory) {
                if (!slot) {
                    item->setPos(837 - item->getWidth() / 2 + 100 * i, 50 - item->getHeight() / 2);
                    slot = item;
                    return;
                }
                i++;
            }
        }
    }
}

void Character::addItem(std::shared_ptr<Item> item) {
    for (std::shared_ptr<Item>& slot : this->inventory) {
        if (!slot) {
            slot = item;
            return;
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