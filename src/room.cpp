//
//  room.cpp
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#include "room.h"

Room::Room(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Room::setActorList(std::list<std::shared_ptr<Actor>> newActorList) {
    this->actorList = newActorList;
}
