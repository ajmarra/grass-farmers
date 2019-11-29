#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <iostream>
#include <list>

#include "actor.h"
#include "item.h"

class MasterLogic;
class Room;

class Character : public Actor {
    private:
        void move(void);

    protected:
		std::shared_ptr<Room> curRoom;
		std::shared_ptr<Item> inventory[4];
        int maxHealth;
        int health;
        int mass;
        double maxSpeed;
        int desiredDirection = -1;
        bool canMove = true;
        float sleepTime = 0;
		int selectedIndex = 0;
    
    public:
        Character(ActorType type, double x, double y, double width, double height, double mass, double maxSpeed, int maxHealth);

        void update(float delta) override;
        
        void damage(int d);

        /**
         * sets the direction that the character wants to go (not necessarily 
         * the same as the current direction it is going, since acceleration).
         * 
         * d -- angle in degrees
         */
        void setDesiredDirection(int d) { this->desiredDirection = d; };

        int getDesiredDirection(void) { return this->desiredDirection; };

        /**
         * stops the character (desiredDirection of -1 stops the character)
         */
        void stop() { this->desiredDirection = -1; };

		int getHealth() { return this->health; };

		int getMaxHealth() { return this->maxHealth; };

		void heal(int healAmount);

		void addItem(void);

		void dropItem(void);

		std::shared_ptr<Item> popItemAtIndex(int index);

        void setSelectedIndex(int index) { this->selectedIndex = index; };

		int getSelectedIndex(void) { return this->selectedIndex; };

		std::shared_ptr<Item> getSelectedItem(void) { return this->inventory[this->selectedIndex]; };

		void setCurrentRoom(std::shared_ptr<Room> room) { this->curRoom = room; };
        
		std::shared_ptr<Room> getCurrentRoom(void) { return this->curRoom; };

		void useItem(int x, int y) { if (this->getSelectedItem()) this->getSelectedItem()->use(x, y); };

        void setCanMove(bool canMove) { this->canMove = canMove; };

        /**
        * Sets a sleep timer and decreases the time on the timer every time it is called.
        * Used for halting Fred while traps are being set and when he sleeps in the bed.
        */
        void sleep(float time) { this->sleepTime = time; };

        float getSleepTime(void) { return this->sleepTime; };
};

#endif
