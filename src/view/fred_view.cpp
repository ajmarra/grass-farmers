#include <SFML/Graphics.hpp>
#include "view/character_view.h"
#include "view/fred_view.h"

FredView::FredView(int health, int experience, int level) {
    this->health = health;
    this->experience = experience;
    this->level = level;
}
