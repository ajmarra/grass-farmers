#ifndef ROOM_H
#define ROOM_H

#include <list>
#include <memory>

#include "actor.h"
#include "item.h"

class Room : public Actor {
private:
    std::list<std::shared_ptr<Actor>> actorList;
    std::list<std::shared_ptr<Item>> itemList;
    
public:
    Room(double x, double y, double width, double height);
    
    void setActorList(std::list<std::shared_ptr<Actor>> newActorList) { this->actorList = newActorList; };

    void setItemList(std::list<std::shared_ptr<Item>> newItemList) { this->itemList = newItemList; };
    
    std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };

    std::list<std::shared_ptr<Item>> &getItemList(void) { return itemList; };
};

#endif