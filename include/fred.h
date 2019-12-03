#ifndef FRED_H
#define FRED_H

#include "actor.h"
#include "character.h"
#include "item.h"
#include "music.h"

class Fred : public Character {
    private:
        Sounds fredDamageSound;

    public:
        

        Fred(double x, double y);

        void damage(int d) override;
};

#endif