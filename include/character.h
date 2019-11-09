#ifndef CHARACTER_H
#define CHARACTER_H

#include "actor.h"
#include "item.h"

#include <memory>
#include <iostream>
#include <list>

class Character : public Actor {
    private:
        void move(void);

    protected:
        int maxHealth;
        int health;
        int mass;
        double maxSpeed;
        int desiredDirection = -1;

		std::shared_ptr<Item> inventory[4];
		std::shared_ptr<Item> selectedItem;
		int selectedIndex = 0;
    
    public:
        Character(ActorType type, double x, double y, double width, double height, double mass, double maxSpeed, int maxHealth);

        void update(float delta) override;
        
        void damage(int d);

        int getDesiredDirection(void) { return this->desiredDirection; };

        /**
         * sets the direction that the character wants to go (not necessarily 
         * the same as the current direction it is going, since acceleration).
         * 
         * d -- angle in degrees
         */
        void setDesiredDirection(int d) { this->desiredDirection = d; };

        /**
         * stops the character (desiredDirection of -1 stops the character)
         */
        void stop() { this->desiredDirection = -1; };

		int getHealth() { return health; };
		int getMaxHealth() { return maxHealth; };

		std::shared_ptr<Item> removeItemAtIndex(int index);

		void dropItem(void);

		void setSelected(int toSelect) {
			selectedItem = inventory[toSelect];
			selectedIndex = toSelect;
		};

		int getSelectedIndex() { return selectedIndex; };
		std::shared_ptr<Item> getSelectedItem() { return selectedItem; };
};

#endif
