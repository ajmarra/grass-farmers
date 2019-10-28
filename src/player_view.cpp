#include "player_view.h"

PlayerView::PlayerView(std::list<std::unique_ptr<Actor>> &actorList, sf::RenderWindow &window)
    : View(actorList) {
    
}