#include "actor.h"

Actor::Actor(double x, double y, double width, double height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->x_speed = 0;
	this->y_speed = 0;
}

void Actor::run(void) {
	x += x_speed;
	y += y_speed;
}

double Actor::get_x(void) {
	return x;
}

double Actor::get_y(void) {
	return y;
}

double Actor::get_x_speed(void) {
	return x_speed;
}

double Actor::get_y_speed(void) {
	return y_speed;
}
