#include <SFML/Graphics.hpp>
#include "character_view.h"
#include "logic/room.h"

CharacterView::CharacterView(int health, int experience, int level) {
    this->health = health;
    this->experience = experience;
    this->level = level;
    // set MasterLogic field
}

void CharacterView::update() {
    // use MasterLogic to check which room to draw
}