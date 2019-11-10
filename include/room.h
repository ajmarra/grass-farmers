#ifndef ROOM_H
#define ROOM_H

#include <list>
#include <memory>

#include "actor.h"

class Room : public Actor {
private:
    std::list<std::shared_ptr<Actor>> actorList;
    
public:
    Room(double x, double y, double width, double height);
    
    void setActorList(std::list<std::shared_ptr<Actor>> newActorList) { this->actorList = newActorList; };
    
    std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
};

#endif