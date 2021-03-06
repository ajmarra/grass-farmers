#ifndef ACTOR_H
#define ACTOR_H

/*
* Base class that all actors in the game inherit from
*/
enum class ActorType { ROOM, EXIT, FRED, ENEMY, HEALTH, MELEEWEAPON, RANGEWEAPON, TRAP, BULLET, PORTAL, CHERYL, BED, CLOSET, SHIELD, SPEED_BOOST };

class Actor {
    protected:
        /**
         * x and y -- the coordinates of the top left pixel
         * width and height -- the number of pixels on the sides
         * speed -- magnitude of the speed of the actor
         */ 
        double x, y, width, height, xSpeed, ySpeed;
        int orientation; // orientation of the actor
        ActorType type; // type of actor

    public:
        Actor(ActorType type, double x, double y, double width, double height);
        
        virtual void update(float delta);

        ActorType getType(void) { return this->type; };

        void setType(ActorType type) { this->type = type; };
        
        void setX(double x) { this->x = x; };

        double getX(void) { return this->x; };

        void setY(double y) { this->y = y; };
        
        double getY(void) { return this->y; };

        void setPos(double x, double y) { this->x = x; this->y = y; };

        double getCenterX(void) { return (this->x + this->width / 2); };

        double getCenterY(void) { return (this->y + this->height / 2); };
        
        double getWidth(void) { return this->width; };

        double getHeight(void) { return this->height; };

        void setWidthHeight(double width, double height) { this->width = width; this->height = height; };

        double getXSpeed(void) { return this->xSpeed; };

        double getYSpeed(void) { return this->ySpeed; };

        double getSpeed(void);

        void hardStop(void) { this->xSpeed = this->ySpeed = 0; };

        double getDirection(void);

        /**
         * Sets the orientation of the actor.
         *
         * d -- direction to face
         */
        void setOrientation(int d) { this->orientation = d; };

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
        void setOrientation(Actor &a);

        /**
         * Returns the orientation of the actor.
         */
        int getOrientation() { return this->orientation; };

        /**
         * Calculates if square Actor a is touching this square actor.
         * (the outer pixels are next to eachother, or the actors are overlapping).
         *
         * a -- the actor for comparison
         */
        bool collidesSquare(Actor &a);

        /**
         * Calculates if circular Actor a is touching this circular actor.
         * (the outer pixels are next to eachother, or the actors are overlapping).
         *
         * a -- the actor for comparison
         */
        bool collidesCircle(Actor &a);

        /**
         * Calculates if Actor a is within a range of this actor.
         *
         * a -- the actor for comparison
         * range -- the distance away from the actor to check within
         */
        bool collidesCircle(Actor &a, int range);

        bool liesInsideSquare(Actor &a);
};

#endif
