#include <SFML/Graphics.hpp>
#include "character_view.h"
#include "fred.h"

Fred::Fred(int health, int experience, int level) {
    this->health = health;
    this->experience = experience;
    this->level = level;
}
