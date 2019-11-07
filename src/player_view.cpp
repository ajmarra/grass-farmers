#include "player_view.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <math.h>
#define PI 3.14159265

PlayerView::PlayerView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<Fred> &fred, std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
    this->fred = fred;
    this->window = window;
}

void PlayerView::pollInput() {
    sf::Event Event;
    int x = 0, y = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) x += 1;

    if (x == 0 && y == 0)
        fred->setDesiredDirection(-1);
    else
        fred->setDesiredDirection(atan2(y, x) * 180 / PI + 360);

	// Collecting an item
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		fred->addItem(this->logic->getItemList());
	}

}

void PlayerView::drawScreen(void) {
    window->clear(sf::Color::Black);

	sf::RectangleShape inventoryBlock1(sf::Vector2f(75, 75));
	sf::RectangleShape inventoryBlock2(sf::Vector2f(75, 75));
	sf::RectangleShape inventoryBlock3(sf::Vector2f(75, 75));
	sf::RectangleShape inventoryBlock4(sf::Vector2f(75, 75));

	inventoryBlock1.setOutlineColor(sf::Color::White);
	inventoryBlock1.setOutlineThickness(5);
	inventoryBlock1.setFillColor(sf::Color::Black);
	inventoryBlock1.setPosition(800, 20);
	inventoryBlock2.setOutlineColor(sf::Color::White);
	inventoryBlock2.setPosition(900, 20);
	inventoryBlock2.setOutlineThickness(5);
	inventoryBlock2.setFillColor(sf::Color::Black);
	inventoryBlock3.setOutlineColor(sf::Color::White);
	inventoryBlock3.setPosition(1000, 20);
	inventoryBlock3.setOutlineThickness(5);
	inventoryBlock3.setFillColor(sf::Color::Black);
	inventoryBlock4.setOutlineColor(sf::Color::White);
	inventoryBlock4.setPosition(1100, 20);
	inventoryBlock4.setOutlineThickness(5);
	inventoryBlock4.setFillColor(sf::Color::Black);

	this->window->draw(inventoryBlock1);
	this->window->draw(inventoryBlock2);
	this->window->draw(inventoryBlock3);
	this->window->draw(inventoryBlock4);

    for (std::list<std::shared_ptr<Actor>>::iterator it = this->logic->getActorList().begin();
        it != this->logic->getActorList().end(); ++it) {
        switch ((*it)->getType()) {
            case ActorType::FRED:
			{
				sf::RectangleShape fredShape(sf::Vector2f((*it)->getWidth(), (*it)->getHeight()));
				fredShape.setFillColor(sf::Color::White);
				fredShape.setPosition((*it)->getX(), (*it)->getY());
				this->window->draw(fredShape);
			}
				break;
			case ActorType::WEAPON:
			{
				sf::RectangleShape itemShape(sf::Vector2f((*it)->getWidth(), (*it)->getHeight()));
				itemShape.setFillColor(sf::Color::Red);
				itemShape.setPosition((*it)->getX(), (*it)->getY());
				this->window->draw(itemShape);
			}
				break;
        }
    }

}

void PlayerView::update(float delta) {
    this->pollInput();
    this->drawScreen();
}