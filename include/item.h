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
	std::shared_ptr<Character> character;

public:
	Item(ActorType type, double x, double y, double width, double height, int quantity, bool stackable);

	bool isStackable(void) { return stackable; };

	int getQuantity(void) { return quantity; };

	void increaseQuantity(void);

	void decreaseQuantity(void);

	void setCharacter(std::shared_ptr<Character> character) { this->character = character; };

	std::shared_ptr<Character> getCharacter(void) { return character; };


	/**
	* Perform whatever is the main function of the item
	*/
	virtual void use(int x, int y) = 0;
};

#endif //ITEM_H