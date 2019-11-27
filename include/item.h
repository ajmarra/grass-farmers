#ifndef ITEM_H
#define ITEM_H

#include "actor.h"

class Character;

#include <iostream>
#include <memory>
/**
 * Initial item logic header.  Any items that could be in the inventory or on the ground will inherit from here.
 */
class Item : public Actor {
private:
	int quantity;
	bool stackable;
    bool canPickUp = true; // Prevents traps from being picked up after being set
    

protected:
	std::shared_ptr<Character> fred;
    bool usedItem = false; // Marks item for removal after used.

public:
	Item(ActorType type, double x, double y, double width, double height, int quantity, bool stackable, std::shared_ptr<Character> fred);

	bool isStackable(void) { return stackable; };

	int getQuantity(void) { return quantity; };

    bool getUsedItem(void) { return usedItem; };

    bool getCanPickUp(void) { return canPickUp; };

    void setCanPickUp(bool toSet) { canPickUp = toSet; };

	void increaseQuantity(void);

	void decreaseQuantity(void);

	void setCharacter(std::shared_ptr<Character> character) { fred = character; };

	std::shared_ptr<Character> getCharacter(void) { return fred; };


	/**
	* Perform whatever is the main function of the item
	*/
	virtual void use(int x, int y) = 0;
};

#endif //ITEM_H