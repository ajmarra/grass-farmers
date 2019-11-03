#include <SFML/Graphics.hpp>
#include "character_view.h"
#include "master_logic.h"

CharacterView::CharacterView(int health, int experience, int level, std::shared_ptr<sf::RenderWindow> window) {
    this->health = health;
    this->experience = experience;
    this->level = level;
    this->window = window;
}

void CharacterView::update(float delta) {
    window->clear(sf::Color::Black);
    
    sf::RectangleShape room;
    room.setSize(sf::Vector2f(curRoom->getWidth(), curRoom->getHeight()));
    room.setPosition(curRoom->getX(), curRoom->getY());
    room.setFillColor(sf::Color::Green);
    window->draw(room);
    
    sf::RectangleShape exit;
    exit.setSize(sf::Vector2f(curExit->getWidth(), curExit->getHeight()));
    exit.setPosition(curExit->getX(), curExit->getY());
    exit.setFillColor(sf::Color::Cyan);
    window->draw(exit);
}

void CharacterView::setCurrentRoom(std::shared_ptr<Room> newCurRoom) {
    curRoom = newCurRoom;
}

void CharacterView::setCurrentExit(std::shared_ptr<Exit> newCurExit) {
    curExit = newCurExit;
}
