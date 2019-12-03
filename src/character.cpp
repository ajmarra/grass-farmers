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

void Character::damage(float d) {
    this->health -= d;
    if (this->health > this->maxHealth) this->health = this->maxHealth;
}

void Character::heal(int healAmount) {
    this->health += healAmount;
    if (this->health > this->maxHealth) this->health = this->maxHealth;
}

void Character::heal(int healAmount, float delta) {
    this->curDelta += delta;
    if (this->curDelta >= this->deltaLimit) {
        this->health += healAmount;
        this->curDelta = 0;
        
        if (this->health > this->maxHealth) this->health = this->maxHealth;
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
    else this->ySpeed = 0;

    if (fabs(this->xSpeed) >= 10.0 / this->mass) {
        this->xSpeed -= (10.0 / this->mass) * cos(this->getDirection() * PI / 180);
    }
    else this->xSpeed = 0;
}

void Character::update(float delta) {
    Actor::update(delta);
    if (this->canMove && this->sleepTime <= 0) {
        Character::move();
    }
    else {
        this->hardStop();
        this->sleepTime -= delta;
        if (sleepTime <= 0) this->canMove = true;
        else this->canMove = false;
    }

    if (this->buffTime > 0) this->buffTime -= delta;
    else if (this->buffTime <= 0 && this->invincibility) this->invincibility = false;
    else if (this->buffTime <= 0 && this->getType() == ActorType::FRED && this->maxSpeed > 200) this->maxSpeed = 200;

    //update items in inventory
    for (std::shared_ptr<Item> &slot : this->inventory) {
        if (slot) {
            slot->update(delta);
        }
    }
}

bool Character::addItem(void) {
    for (std::shared_ptr<Item> item : this->curRoom->getItemList()) {
        if (this->collidesSquare(*item) && item->getCanPickUp()) {
            if (this->addItem(item)) {
                this->curRoom->removeActor(item); // remove from room
                return true;
            }
        }
    }
    return false;
}

bool Character::addItem(std::shared_ptr<Item> item) {
    // if stackable, increment
    if (item->isStackable()) {
        for (std::shared_ptr<Item> &slot : this->inventory) {
            if (slot && item->getType() == slot->getType()) {
                item->setCharacter(this->shared_from_this()); // set owned by this character
                slot->increaseQuantity();
                return true;
            }
        }
    }

    // add to next empty slot
    int i = 0;
    for (std::shared_ptr<Item> &slot : this->inventory) {
        if (!slot) {
            item->setCharacter(this->shared_from_this()); // set owned by this character
            item->setPos(837 - item->getWidth() / 2 + 100 * i, 50 - item->getHeight() / 2);
            slot = item;
            return true;
        }
        i++;
    }
    return false;
}

std::shared_ptr<Item> Character::popItemAtIndex(int index) {
    std::shared_ptr<Item> toReturn = this->inventory[index];
    this->inventory[index] = nullptr;
    return (toReturn);
}

void Character::dropItem(void) {
    std::shared_ptr<Item> toDrop = this->popItemAtIndex(selectedIndex);
    if (toDrop == nullptr) return;
    toDrop->setPos(this->getCenterX(), this->getCenterY());
    this->getCurrentRoom()->addActor(toDrop);
}

void Character::destroyItem(void) {
    this->inventory[this->selectedIndex] = nullptr;
}