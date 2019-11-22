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
        std::list<std::shared_ptr<Actor>> actorList;
        std::list<std::shared_ptr<Item>> itemList;
        std::list<std::shared_ptr<Enemy>> enemyList;
        std::list<std::shared_ptr<Exit>> exitList;
        std::list<std::list<std::shared_ptr<Actor>>::iterator> actorListSections; // List of iterators pointing to sections of each type of actor within the actor list
        
    public:
        Room(double x, double y, double width, double height);
        
        void setActorList(std::list<std::shared_ptr<Actor>> newActorList) { this->actorList = newActorList; };
        
        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };

        void addActor(std::shared_ptr<Actor> actor);
};

#endif