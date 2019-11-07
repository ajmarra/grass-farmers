#include "actor.h"
#include "character.h"
#include "item.h"

#include <memory>
#include <iostream>
#include <list>

Character::Character(ActorType type, double x, double y, double width, double height, double mass, double topSpeed, int maxHealth)
    : Actor(type, x, y, width, height) {
    this->mass = mass;
    this->topSpeed = topSpeed;
	this->health = maxHealth;
    this->maxHealth = maxHealth;
}

void Character::damage(int d) {
    health -= d;
    if (health > maxHealth) health = maxHealth;
}

void Character::update(float delta) {
    Actor::update(delta);

    if (desiredDirection >= 0) {
        xSpeed = topSpeed * cos(desiredDirection * (PI / 180));
        ySpeed = topSpeed * sin(desiredDirection * (PI / 180));
    }
    else {
        xSpeed = ySpeed = 0;
    }
}

std::shared_ptr<Item> Character::removeItemAtIndex(int index) {
	std::shared_ptr<Item> toReturn = inventory[index];
	inventory[index] = nullptr;
	return (toReturn);
}

void Character::dropItem() {
	std::shared_ptr<Item> toDrop = this->removeItemAtIndex(selectedIndex);
	if (toDrop != nullptr) toDrop->setXY(this->getCenterX(), this->getCenterY());
}
