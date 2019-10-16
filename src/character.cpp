#include "character.h"
#include "actor.h"

Character::Character(double x, double y, double width, double height, double weight, double topSpeed)
    : Actor(x, y, width, height) {
    this->weight = weight;
    this->topSpeed = topSpeed;
}

void Character::setMovement(int d) {

}