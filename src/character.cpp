#include "actor.h"
#include "character.h"
#include "item.h"

#include <memory>
#include <iostream>
#include <list>

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
	Character::move();
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
