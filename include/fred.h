#ifndef FRED_H
#define FRED_H

#include "actor.h"
#include "character.h"
#include "item.h"

class Fred : public Character {
    private:
        Item* inventory[4];

    public:
        Fred(double x, double y);
		
		void addItem(Item* toAdd);
		Item* getItemAtIndex(int index) { return this->inventory[index]; };
		Item* removeItemAtIndex(int index);
		
};

#endif