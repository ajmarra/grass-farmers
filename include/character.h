#ifndef CHARACTER_H
#define CHARACTER_H

#include "actor.h"

class Character : public Actor {
    protected:
        int weight;
        double topSpeed;
    
    public:
        Character(double x, double y, double width, double height, double weight, double topSpeed);

        /**
         * sets the direction that the character wants to go.
         * 
         * d -- angle in degrees
        */
        void setMovement(int d);
};

#endif