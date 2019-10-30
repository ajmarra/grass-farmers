#include "master_view.h"

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> &window) {
    this->window = window;
}

void MasterView::init(std::list<std::shared_ptr<Actor>> &actorList) {
    this->actorList = actorList;
}

void MasterView::setPlayer(std::shared_ptr<Fred> &fred) {
    player = std::make_shared<PlayerView>(this->actorList, fred, this->window);
}

void MasterView::update(float delta) {
    player->update(delta);
}