#include "actor.h"

Actor::Actor(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->xSpeed =
    this->ySpeed =
    this->direction = 0;
}

void Actor::update(void) {
    x += xSpeed;
    y += ySpeed;
}

void Actor::setFacing(int x, int y) {
    float yDiff = this->getCenterX() - x;
    float xDiff = this->getCenterY() - y;
    this->direction = atan(xDiff / yDiff) * 180 / PI;
}

void Actor::setFacing(Actor a) {
    float xDiff = this->getCenterX() - a.getCenterX();
    float yDiff = this->getCenterY() - a.getCenterY();
    this->direction = atan(xDiff / yDiff) * 180 / PI;
}

bool Actor::collides(Actor a) {
    return (
        a.getX() <= this->x + this->width &&
        a.getX() + a.getWidth() >= this->x &&
        a.getY() <= this->y + this->height &&
        a.getY() + a.getHeight() >= this->y
    );
}