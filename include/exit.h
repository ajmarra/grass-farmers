#ifndef EXIT_H
#define EXIT_H

#include <memory>

#include "actor.h"
#include "room.h"

class Exit : public Actor {
    protected:
        std::shared_ptr<Room> destination;
        
    public:
        Exit(double x, double y, std::shared_ptr<Room> destination);

        std::shared_ptr<Room> getDestination() { return this->destination; };

        void setDestination(std::shared_ptr<Room> destination) { this->destination = destination; };
};

#endif