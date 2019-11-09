#ifndef ACTOR_H
#define ACTOR_H

enum class ActorType { ROOM, EXIT, FRED, ENEMY, HEALTH, WEAPON, BULLET, TRAP };

class Actor {
    protected:
        /**
         * x and y -- the coordinates of the top left pixel
         * width and height -- the number of pixels on the sides
		 * speed -- magnitude of the speed of the actor
         */ 
        double x, y, width, height, xSpeed, ySpeed;
		int orientation; //orientation of the actor
        ActorType type;

    public:
		Actor() { }; //Do not use default constructor. Left here because Item class currently uses it.
        
        Actor(ActorType type, double x, double y, double width, double height);
        
        virtual void update(float delta);

        ActorType getType() { return this->type; };
        
        double getX(void) { return this->x; };
        
        double getY(void) { return this->y; };

		void setXY(double x, double y) {
			this->x = x;
			this->y = y;
		};

        double getCenterX(void) { return (this->x + this->width / 2); };

        double getCenterY(void) { return (this->y + this->height / 2); };
        
        double getWidth(void) { return this->width; };

        double getHeight(void) { return this->height; };

        double getXSpeed(void) { return xSpeed; };

		double getYSpeed(void) { return ySpeed; };

		double getSpeed(void);

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
		void setOrientation(Actor a);

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
		bool collidesSquare(Actor a);

		/**
		 * Calculates if circular Actor a is touching this circular actor.
		 * (the outer pixels are next to eachother, or the actors are overlapping).
		 *
		 * a -- the actor for comparison
		 */
		bool collidesCircle(Actor a);

		bool liesInsideSquare(Actor a);
    
        void hardStop() { this->xSpeed = 0; this->ySpeed = 0; };
};

#endif
