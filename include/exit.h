#ifndef EXIT_H
#define EXIT_H

#include <memory>

#include "actor.h"
#include "room.h"

/* Exits to each of the rooms */
class Exit : public Actor {
    protected:
        int destination;
        
    public:
        Exit(double x, double y, int destination);

        int getDestination(void) { return this->destination; };

        void setDestination(int destination) { this->destination = destination; };
};

#endif