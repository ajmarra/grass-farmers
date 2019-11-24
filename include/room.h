#ifndef ROOM_H
#define ROOM_H

#include <list>
#include <memory>

#include "actor.h"
#include "character.h"
#include "item.h"
#include "enemy.h"
#include "exit.h"

class Room : public Actor {
    private:
        // Actor list
        std::list<std::shared_ptr<Actor>> actorList;
        // List of iterators pointing to sections of each type of actor within the actor list
        std::list<std::list<std::shared_ptr<Actor>>::iterator> actorListSections;
        
    public:
        Room(double x, double y, double width, double height);
        
        void setActorList(std::list<std::shared_ptr<Actor>> newActorList) { this->actorList = newActorList; };
        
        /**
         * Adds an actor to the actor list in the proper section for actors of its type.
         */
        void addActor(std::shared_ptr<Actor> actor);

        /**
         * Return the list of actors.
         */
        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };

        /**
         * Return a list of actors of type t.
         */
        std::list<std::shared_ptr<Actor>> &getActorList(ActorType t);
};

#endif