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
		fred->addItem(logic->getItemList());
	}

}

void PlayerView::drawScreen(void) {
    window->clear(sf::Color::Black);

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