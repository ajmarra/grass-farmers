#ifndef ACTOR_H
#define ACTOR_H

#include "math.h"
#define PI 3.14159265

enum class ActorType { ROOM, EXIT, FRED, ENEMY, WEAPON, BULLET, TRAP };

class Actor {
    protected:
        /**
         * x and y -- the coordinates of the top left pixel
         * width and height -- the number of pixels on the sides
         */ 
        double x, y, xSpeed, ySpeed, width, height;
        int direction;
        ActorType type;

    public:
		Actor() { };
        
        Actor(ActorType type, double x, double y, double width, double height);
        
        virtual void update(float delta);

        ActorType getType() { return this->type; };
        
        double getX(void) { return x; };
        
        double getY(void) { return y; };

        double getCenterX(void) { return (x + width / 2); };

        double getCenterY(void) { return (y + height / 2); };
        
        double getWidth(void) { return width; };

        double getHeight(void) { return height; };

        double getXSpeed(void) { return xSpeed; };

        void setXSpeed(int s) { this->xSpeed = s; };
        
        double getYSpeed(void) { return ySpeed; };

        void setYSpeed(int s) { this->ySpeed = s; };

        /**
         * Sets the direction of movement.
         * 
         * d -- direction
         */
        void setDirection(int d) { direction = d; };

        int getDirection(void) { return direction; };

        /**
         * Sets the orientation of the actor.
         * 
         * x -- x coordinate to face
         * y -- y coordinate to face
         */
        void setFacing(int x, int y);

        /**
         * Sets the orientation of the actor.
         * 
         * a -- the actor to face towards
         */
        void setFacing(Actor a);

        /**
         * Calculates if Actor a is touching this actor.
         * (the outer pixels are next to eachother, or the actors are overlapping).
         * 
         * a -- the actor for comparison
         */
        bool collides(Actor a);
};

#endif