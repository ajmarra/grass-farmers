#include "actor.h"

Actor::Actor(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->xSpeed = 0;
    this->ySpeed = 0;
}

void Actor::run(void) {
    x += xSpeed;
    y += ySpeed;
}

double Actor::getX(void) {
    return x;
}

double Actor::getX(void) {
    return y;
}

double Actor::getWidth(void) {
    return width;
}

double Actor::getHeight(void) {
    return height;
}

double Actor::getXSpeed(void) {
    return xSpeed;
}

double Actor::getYSpeed(void) {
    return ySpeed;
}

bool Actor::collides(Actor a) {
    return (
        a.getX() <= this->x + this->width &&
        a.getX() + a.getWidth() >= this->x &&
        a.getY() <= this->y + this->height &&
        a.getY() + a.getHeight() >= this->y
    )
}