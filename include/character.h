#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <iostream>
#include <list>

#include "actor.h"
#include "item.h"

class MasterLogic;
class Room;

class Character : public Actor, public std::enable_shared_from_this<Character> {
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
        float buffTime = 0;
        bool invincibility = false;
		int selectedIndex = 0;
        int selectedClosetIndex = 0;
    
        float curDelta = 0;
        const float deltaLimit = 0.5;
    
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
        void stop(void) { this->desiredDirection = -1; };

		int getHealth(void) { return this->health; };

		int getMaxHealth(void) { return this->maxHealth; };

		void heal(int healAmount);
        void heal(int healAmount, float delta);

        std::shared_ptr<Item> *getInventory(void) { return (this->inventory); };

		void addItem(void);

		void dropItem(void);

        // Used for enemy inventory
        void addItem(std::shared_ptr<Item> item);

		std::shared_ptr<Item> popItemAtIndex(int index);

        void setSelectedIndex(int index) { this->selectedIndex = index; };

		int getSelectedIndex(void) { return this->selectedIndex; };

		std::shared_ptr<Item> getSelectedItem(void) { return this->inventory[this->selectedIndex]; };
    
        void setSelectedClosetIndex(int n) { selectedClosetIndex = n; };
    
        int getSelectedClosetIndex() { return selectedClosetIndex; };
    
		void setCurrentRoom(std::shared_ptr<Room> room) { this->curRoom = room; };
        
		std::shared_ptr<Room> getCurrentRoom(void) { return this->curRoom; };

		void useItem(int x, int y) { if (this->getSelectedItem()) this->getSelectedItem()->use(x, y); };

        void setCanMove(bool canMove) { this->canMove = canMove; };

        bool getCanMove(void) { return this->canMove; };

        /**
        * Sets a sleep timer and decreases the time on the timer every time it is called.
        * Used for halting Fred while traps are being set.
        */
        void sleep(float time) { this->sleepTime = time; };

        float getSleepTime(void) { return this->sleepTime; };

        void setBuffTime(float time) { this->buffTime = time; };

        float getBuffTime(void) { return this->buffTime; };

        void setInvincibility(bool toSet) { this->invincibility = toSet; };

        bool getInvincibility(void) { return this->invincibility; };

        // The following two methods used to scale Cheryl's stats during final boss battle
        void setMaxSpeed(double maxSpeed) { this->maxSpeed = maxSpeed; };
        void setMass(double mass) { this->mass = mass; };
};

#endif
