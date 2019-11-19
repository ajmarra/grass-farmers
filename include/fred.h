#ifndef FRED_H
#define FRED_H

#include "actor.h"
#include "character.h"
#include "item.h"

#include <memory>
#include <list>
#include <iostream>

class Fred : public Character {

    public:
        Fred(double x, double y);
		
		std::shared_ptr<Item> getItemAtIndex(int index) { return this->inventory[index]; };

		void useSelectedItem(void);

		
};

#endif