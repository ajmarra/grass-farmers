#include "actor.h"

Actor::Actor(ActorType type, double x, double y, double width, double height) {
    this->type = type;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed =
    this->direction = 0;
}

void Actor::update(float delta) {
    //sanity check
    if (this->speed < 0) this->speed = 0;

    x += speed * sin(this->direction * (PI / 180)) * delta;
    y += speed * sin(this->direction * (PI / 180)) * delta;
}

void Actor::setOrientation(int x, int y) {
    float yDiff = this->getCenterX() - x;
    float xDiff = this->getCenterY() - y;
    this->orientation = atan(xDiff / yDiff) * 180 / PI;
}

void Actor::setOrientation(Actor a) {
    float xDiff = this->getCenterX() - a.getCenterX();
    float yDiff = this->getCenterY() - a.getCenterY();
    this->orientation = atan(xDiff / yDiff) * 180 / PI;
}

bool Actor::collides(Actor a) {
    return (
        a.getX() <= this->x + this->width &&
        a.getX() + a.getWidth() >= this->x &&
        a.getY() <= this->y + this->height &&
        a.getY() + a.getHeight() >= this->y
    );
}