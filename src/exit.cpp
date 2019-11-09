//
//  exit.cpp
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#include <exit.h>

Exit::Exit(double x, double y, double width, double height, std::shared_ptr<Room> destination) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->destination = destination;
}

std::shared_ptr<Room> Exit::getDestination() {
    return destination;
}

void Exit::setDestination(std::shared_ptr<Room> newDest) {
    this->destination = newDest;
}
