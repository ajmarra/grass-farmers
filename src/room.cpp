#include "room.h"
#include "actor.h"

Room::Room(double x, double y, double width, double height) : Actor(ActorType::ROOM, x, y, width, height) { }

void Room::addActor(std::shared_ptr<Actor> &actor) {
    actorList.unique(); //If all actors of one type are removed, removes the duplicate pointer

    // put the actor in the appropriate section of actors
    for (std::list<std::shared_ptr<Actor>>::iterator &section : this->actorListSections) {
        if ((*section)->getType() == actor->getType()) {
            this->actorList.insert(section--, actor);
            return;
        }
    }

    // If section not found, add a new section of actor type actor.getType()
    this->actorList.push_back(actor);
    this->actorListSections.push_back(--actorList.end());
}

std::list<std::shared_ptr<Actor>> &Room::getActorList(ActorType t) {
    std::list<std::shared_ptr<Actor>> returnList { };

    // Search for the proper list section
    for (std::list<std::shared_ptr<Actor>>::iterator &section : this->actorListSections) {
        if ((*section)->getType() == t) {
            returnList.splice(returnList.begin(), this->actorList, section, ++section);
            return (returnList);
        }
    }

    // Return empty list if none of type t are found
    return (returnList);
}