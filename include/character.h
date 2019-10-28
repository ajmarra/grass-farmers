#ifndef CHARACTER_H
#define CHARACTER_H

#include "actor.h"

class Character : public Actor {
    protected:
        int maxHealth;
        int health;
        int mass;
        double topSpeed;
        int desiredDirection;
    
    public:
        Character(double x, double y, double width, double height, double weight, double topSpeed, int maxHealth);

        void update(float dt) override;
        
        void damage(int d);

        /**
         * sets the direction that the character wants to go (not necessarily 
         * the same as the current direction it is going, since acceleration).
         * 
         * d -- angle in degrees
         */
        void setDesiredDirection(int d) { this->desiredDirection = d; };

        /**
         * 
         */
        void stop() { this->desiredDirection = -1; };
};

#endif