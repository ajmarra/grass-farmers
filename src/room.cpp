#include "room.h"
#include "actor.h"

Room::Room(double x, double y, double width, double height) : Actor(ActorType::ROOM, x, y, width, height) { }

void Room::addActor(std::shared_ptr<Actor> actor) {
    for (std::list<std::list<std::shared_ptr<Actor>>::iterator>::iterator section = this->actorListSections.begin();
        section != this->actorListSections.end(); section++) {
        
    }
    
    this->actorList.push_back(actor);
    switch(actor->getType()) {
        case ActorType::EXIT:
            this->exitList.push_back(actor);
            break;
    }
}