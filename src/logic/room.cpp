//
//  room.cpp
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#include "logic/room.h"

Room::Room(double x, double y, double width, double height, &Exit exit) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->exit = exit;
}

const &Exit Room::getExit() {
    return exit;
}
