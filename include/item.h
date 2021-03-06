#ifndef ITEM_H
#define ITEM_H

#include "actor.h"

#include <iostream>
#include <memory>

class Character;

/**
 * Initial item logic header. Any items that could be in the inventory or on the ground will inherit from here.
 */
class Item : public Actor {
    private:
        int quantity;
        bool stackable;
        bool canPickUp = true; // Prevents traps from being picked up after being set
        bool usedItem = false; // Marks item for removal after used.
        
    protected:
        std::shared_ptr<Character> character;
        float reloading = 0;
        float loadTime;

    public:
        Item(ActorType type, double x, double y, double width, double height, int quantity, bool stackable);

        bool isStackable(void) { return stackable; };

        int getQuantity(void) { return quantity; };

        bool getUsedItem(void) { return usedItem; };
        
        void setUsedItem(bool isUsed) { usedItem = isUsed; };

        bool getCanPickUp(void) { return canPickUp; };

        void setCanPickUp(bool toSet) { canPickUp = toSet; };

        void increaseQuantity(void);

        void decreaseQuantity(void);

        float getLoadTime(void) { return this->loadTime; };
        
        float getReloading(void) { return this->reloading; };
        
        void setCharacter(std::shared_ptr<Character> character) { this->character = character; };

        std::shared_ptr<Character> getCharacter(void) { return this->character; };

        /**
        * Perform whatever is the main function of the item
        */
        virtual void use(int x, int y) = 0;
};

#endif