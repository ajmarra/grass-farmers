#include <SFML/Graphics.hpp>
#include "character_view.h"
#include "fred_view.h"

FredView::FredView(int health, int experience, int level) {
    this->health = health;
    this->experience = experience;
    this->level = level;
}
