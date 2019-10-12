#ifndef ACTOR_H
#define ACTOR_H

class Actor {
    protected:
        double x, y, x_speed, y_speed, width, height;

    public:
        Actor(double x, double y, double width, double height);
        
        virtual void run(void);
        
        virtual void reset(void) = 0;
        
        double getX(void);
        
        double getY(void);
        
        double getWidth(void);

        double getHeight(void);

        double getXSpeed(void);
        
        double getYSpeed(void);

        bool collides(Actor a);
};

#endif