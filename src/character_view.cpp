#include <SFML/Graphics.hpp>
#include "character_view.h"
#include "logic/room.h"
#include "master_logic.h"

CharacterView::CharacterView(int health, int experience, int level) {
    this->health = health;
    this->experience = experience;
    this->level = level;
}

void CharacterView::update(float delta) {
    sf::RectangleShape room;
    room.setSize(sf::Vector2f(curRoom->getWidth(), curRoom->getHeight()));
    room.setPosition(curRoom->getX(), curRoom->getY());
}

void CharacterView::setCurrentRoom(std::shared_ptr<Room> newCurRoom) {
    curRoom = newCurRoom;
}
