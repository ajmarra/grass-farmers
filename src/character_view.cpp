#include <SFML/Graphics.hpp>
#include "character_view.h"

CharacterView::CharacterView(int health, int experience, int level) {
    this->health = health;
    this->experience = experience;
    this->level = level;
}
