#ifndef FRED_H
#define FRED_H

#include "actor.h"
#include "character.h"
#include "item.h"

class Fred : public Character {
    private:
        Item *inventory[5];

    public:
        Fred(double x, double y);
};

#endif