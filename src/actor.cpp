#include "math.h"

#include "actor.h"

#define PI 3.14159265

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
    float x = this->getCenterX() - x;
    float y = this->getCenterY() - y;
    this->direction = atan(y / x);
}

void Actor::setFacing(Actor a) {
    float x = this->getCenterX() - a.getCenterX();
    float y = this->getCenterY() - a.getCenterY();
    this->direction = atan(y / x);
}

bool Actor::collides(Actor a) {
    return (
        a.getX() <= this->x + this->width &&
        a.getX() + a.getWidth() >= this->x &&
        a.getY() <= this->y + this->height &&
        a.getY() + a.getHeight() >= this->y
    );
}