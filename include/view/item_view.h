#ifndef ITEM_H
#define ITEM_H

#include <logic/actor.h>

class ItemView : public Actor {
private:
	int quantity, x, y;
	bool stackable;
	sf::RectangleShape itemShape;

public:
	ItemView(int x, int y, int quantity, bool stackable);


};

#endif //ITEM_H