#ifndef EXIT_H
#define EXIT_H

#include <memory>

#include "actor.h"
#include "room.h"

class Exit : public Actor {
    protected:
        std::list<std::shared_ptr<Room>>::iterator destination;
        
    public:
        Exit(double x, double y, std::list<std::shared_ptr<Room>>::iterator destination);

        std::list<std::shared_ptr<Room>>::iterator getDestination() { return this->destination; };

        void setDestination(std::list<std::shared_ptr<Room>>::iterator destination) { this->destination = destination; };
};

#endif