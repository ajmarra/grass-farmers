#include <SFML/Graphics.hpp>
#include "character_view.h"
#include "logic/room.h"
#include "master_logic.h"

CharacterView::CharacterView(int health, int experience, int level, MasterLogic& logic) : logic(logic) {
    this->health = health;
    this->experience = experience;
    this->level = level;
}

void CharacterView::update() {
    std::shared_ptr<Room> curRoom = logic.getCurrentRoom();
}
