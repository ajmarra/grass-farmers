#ifndef ITEM_H
#define ITEM_H

#include "actor.h"

/**
 * Initial item logic header.  Any items that could be in the inventory or on the ground will inherit from here.
 */
class Item : public Actor {
	private:
		int quantity; //Do we still need this and its associated methods?
		bool stackable;

	public:
		Item(ActorType type, double x, double y, double width, double height, int quantity, bool stackable);

		bool isStackable(void) { return stackable; };

		int getQuantity(void) { return quantity; };

		void increaseQuantity(void);

		void decreaseQuantity(void);

		/**
		 * Perform whatever is the main function of the item
		 */
		virtual void use(int x, int y) = 0;

		//void collectItem(Item toCollect);
};

#endif