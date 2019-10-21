#ifndef ITEM_H
#define ITEM_H

#include <logic/actor.h>

class ItemView : public Actor {
private:
	int quantity;
	bool stackable;

public:
	ItemView() {};
	ItemView(int quantity, bool stackable);


};

#endif //ITEM_H