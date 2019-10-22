#ifndef ITEM_VIEW_H
#define ITEM_VIEW_H

#include <actor.h>

class ItemView : public Actor {
private:
	int quantity, x, y;
	bool stackable;
	sf::RectangleShape itemShape;

public:
	ItemView(int x, int y, int quantity, bool stackable);

	sf::RectangleShape getItemShape(void) { return (itemShape); };


};

#endif //ITEM_VIEW_H