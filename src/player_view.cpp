#include "player_view.h"

PlayerView::PlayerView(std::list<std::shared_ptr<Actor>> &actorList, int control, sf::RenderWindow &window)
    : View(actorList, control) {
    
}