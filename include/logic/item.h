// Initial item logic header.  Any items that could be in the inventory or on the ground will inherit from here.
#ifndef ITEM_H
#define ITEM_H

#include "actor.h"

class Item : public Actor {
private:
	int quantity;
	bool stackable;

public:
	Item(int x, int y, int quantity, bool stackable);

	bool isStackable(void);

	int getQuantity(void);
	void increaseQuantity(void);
	void decreaseQuantity(void);

	//void collectItem(Item toCollect);
};

#endif //ITEM_H