#include <SFML/Graphics.hpp>
#include <logic/item.h>
#include<view/item_view.h>
#include <logic/actor.h>

ItemView::ItemView(int x, int y, int quantity, bool stackable) {
	this->x = x;
	this->y = y;
	this->quantity = quantity;
	this->stackable = stackable;

	sf::Vector2f itemSize(10, 10);
	this->itemShape.setSize(itemSize);
	this->itemShape.setFillColor(sf::Color::Red);
	this->itemShape.setOrigin(x, y);
}