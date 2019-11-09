#include "player_view.h"
#include "sprites.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <math.h>
#define PI 3.14159265

PlayerView::PlayerView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<Fred> &fred, std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
    this->fred = fred;
    this->window = window;
	
	
	FredSprite.spriteMap.loadFromFile("../resources/fredWALK.png");
	
	FredSprite.spriteFrame.top = 64;//x
	FredSprite.spriteFrame.left = 0;//y
	FredSprite.spriteFrame.width = 64;
	FredSprite.spriteFrame.height = 64;

}

void PlayerView::pollInput() {
    sf::Event Event;
    int x = 0, y = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) y += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) x += 1;

    if (x == 0 && y == 0) fred->stop();
    else fred->setDesiredDirection(rint(atan2(y, x) * 180.0 / PI + 360));

	// Collecting an item
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		fred->addItem(this->logic->getItemList());
	}
	
	// Drop an item
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		fred->dropItem();
	}

	// Inventory selection
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) fred->setSelected(0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) fred->setSelected(1);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) fred->setSelected(2);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) fred->setSelected(3);
	
	

}

void PlayerView::drawScreen(void) {
    window->clear(sf::Color::Green);

	//Fred's Health Bar
	sf::RectangleShape maxHealthBar(sf::Vector2f(5*fred->getMaxHealth(), 20));
	maxHealthBar.setPosition(10, 20);
	maxHealthBar.setFillColor(sf::Color::Blue);

	this->window->draw(maxHealthBar);

	// Hard coded inventory blocks
	sf::RectangleShape inventoryBlock1(sf::Vector2f(75, 75));
	sf::RectangleShape inventoryBlock2(sf::Vector2f(75, 75));
	sf::RectangleShape inventoryBlock3(sf::Vector2f(75, 75));
	sf::RectangleShape inventoryBlock4(sf::Vector2f(75, 75));

	if (fred->getSelectedIndex() == 0) inventoryBlock1.setOutlineColor(sf::Color::Green); 
	else inventoryBlock1.setOutlineColor(sf::Color::White); 
	inventoryBlock1.setPosition(800, 20);
	inventoryBlock1.setOutlineThickness(5);
	inventoryBlock1.setFillColor(sf::Color::Black);
	if (fred->getSelectedIndex() == 1) inventoryBlock2.setOutlineColor(sf::Color::Green);
	else inventoryBlock2.setOutlineColor(sf::Color::White);
	inventoryBlock2.setPosition(900, 20);
	inventoryBlock2.setOutlineThickness(5);
	inventoryBlock2.setFillColor(sf::Color::Black);
	if (fred->getSelectedIndex() == 2) inventoryBlock3.setOutlineColor(sf::Color::Green);
	else inventoryBlock3.setOutlineColor(sf::Color::White);
	inventoryBlock3.setPosition(1000, 20);
	inventoryBlock3.setOutlineThickness(5);
	inventoryBlock3.setFillColor(sf::Color::Black);
	if (fred->getSelectedIndex() == 3) inventoryBlock4.setOutlineColor(sf::Color::Green);
	else inventoryBlock4.setOutlineColor(sf::Color::White);
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
				fredShape.setTexture(&FredSprite.spriteMap);
				fredShape.setTextureRect(FredSprite.spriteFrame);
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
	FredSprite.update(delta,fred->getDirection());
    this->drawScreen();
}