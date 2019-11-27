#ifndef BED_H
#define BED_H

#include "actor.h"

class Bed : public Actor {
    private:
        int healAmount;
    
    public:
        Bed(ActorType type, double x, double y, double width, double height, int healAmt);
        int getHealAmount();
};

#endif
