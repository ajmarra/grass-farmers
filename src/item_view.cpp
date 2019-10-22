#include <SFML/Graphics.hpp>
#include "item.h"
#include "item_view.h"
#include "actor.h"

ItemView::ItemView(int x, int y, int quantity, bool stackable) {
	this->x = x;
	this->y = y;
	this->quantity = quantity;
	this->stackable = stackable;

	sf::Vector2f itemSize(20, 20);
	this->itemShape.setSize(itemSize);
	this->itemShape.setFillColor(sf::Color::Red);
	this->itemShape.setOrigin(x, y);
}