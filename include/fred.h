#ifndef FRED_H
#define FRED_H

#include "actor.h"
#include "character.h"
#include "item.h"

#include <memory>
#include <list>
#include <iostream>

class Fred : public Character {
    private:
		std::shared_ptr<Item> inventory[4];

    public:
        Fred(double x, double y);
		
		void addItem(std::list<std::shared_ptr<Item>> itemList);
		std::shared_ptr<Item> getItemAtIndex(int index) { return this->inventory[index]; };
		std::shared_ptr<Item> removeItemAtIndex(int index);
		
};

#endif