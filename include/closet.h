#ifndef CLOSET_H
#define CLOSET_H

#include "actor.h"
#include "item.h"

class Closet : public Actor {
    private:
        std::shared_ptr<Item> closetItems[20];
    
    public:
        Closet(ActorType type, double x, double y, double width, double height);
    
        std::shared_ptr<Item> getItemAtIndex(int index);
    
        void putItemAtIndex(int index, std::shared_ptr<Item> newItem);
};

#endif
