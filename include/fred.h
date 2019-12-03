#ifndef FRED_H
#define FRED_H

#include "actor.h"
#include "character.h"
#include "item.h"
#include "music.h"

/* The hero and controllable character of the game */
class Fred : public Character {
    private:
        Sounds fredDamageSound;

    public:
        

        Fred(double x, double y);

        void damage(float d) override;
};

#endif