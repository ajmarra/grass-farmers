#ifndef BED_H
#define BED_H

/*
* When Fred collides with the bed he slowly regains health as if he were resting.
*/
#include "actor.h"

class Bed : public Actor {
    private:
        int healAmount;
    
    public:
        Bed(ActorType type, double x, double y, double width, double height, int healAmt);
        int getHealAmount();
};

#endif
