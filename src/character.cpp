#include "actor.h"
#include "character.h"
#include "item.h"

#include "math.h"
#define PI 3.14159265

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
	if (this->canMove) {
		Character::move();
	}
	else this->hardStop();
}

void Character::addItem(std::list<std::shared_ptr<Item>> itemList) {
	bool notAdded = true;
	int i = 0;
	std::shared_ptr<Item> toAdd;
	for (std::list<std::shared_ptr<Item>>::iterator it = itemList.begin(); it != itemList.end(); ++it) {
		if (this->collidesSquare(*(*it))) {
			toAdd = (*it);
			i = 0;
			while (notAdded) {
				if (toAdd->isStackable() && inventory[i] != nullptr && inventory[i]->getType() == toAdd->getType()) {
					inventory[i]->increaseQuantity();
					notAdded = false;
					// TODO: need to figure out what to do with old/used items.
				}
				else if (i == 4) notAdded = false;
				else if (inventory[i] == nullptr) {
					inventory[i] = toAdd;
					notAdded = false;
					if (i == 0) {
						toAdd->setXY(825, 40);
						toAdd->setCharacter(std::make_shared<Character>(*this));
					}
					else if (i == 1) {
						toAdd->setXY(925, 40);
                        toAdd->setCharacter(std::make_shared<Character>(*this));
					}
					else if (i == 2) {
						toAdd->setXY(1025, 40);
                        toAdd->setCharacter(std::make_shared<Character>(*this));
					}
					else if (i == 3) {
						toAdd->setXY(1125, 40);
                        toAdd->setCharacter(std::make_shared<Character>(*this));
					}
					if (selectedIndex == i) this->setSelected(i);
				}
				i++;
			}

			break;
		}
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
