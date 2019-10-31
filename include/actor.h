#ifndef ACTOR_H
#define ACTOR_H

#include "math.h"
#define PI 3.14159265

class Actor {
    protected:
        /**
         * x and y -- the coordinates of the top left pixel
         * width and height -- the number of pixels on the sides
         * speed -- magnitude of the speed of the actor
         */ 
        double x, y, width, height, speed;
        int orientation, direction; //orientation and direction of movement

    public:
        Actor(double x, double y, double width, double height);
        
        virtual void update(float delta);
        
        double getX(void) { return this->x; };
        
        double getY(void) { return this->y; };

        double getCenterX(void) { return (this->x + this->width / 2); };

        double getCenterY(void) { return (this->y + this->height / 2); };
        
        double getWidth(void) { return this->width; };

        double getHeight(void) { return this->height; };

        void setSpeed(int s) { this->speed = s; };

        double getSpeed(void) { return this->speed; };

        /**
         * Sets the direction of movement.
         * 
         * d -- direction
         */
        void setDirection(int d) { this->direction = d; };

        int getDirection(void) { return this->direction; };

        /**
         * Sets the orientation of the actor.
         * 
         * x -- x coordinate to face
         * y -- y coordinate to face
         */
        void setOrientation(int x, int y);

        /**
         * Sets the orientation of the actor.
         * 
         * a -- the actor to face towards
         */
        void setOrientation(Actor a);

        int getOrientation() { return this->orientation; };

        /**
         * Calculates if Actor a is touching this actor.
         * (the outer pixels are next to eachother, or the actors are overlapping).
         * 
         * a -- the actor for comparison
         */
        bool collides(Actor a);
};

#endif