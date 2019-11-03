#include "master_view.h"

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> &window) {
    this->window = window;
}

void MasterView::init(std::list<std::shared_ptr<Actor>> &actorList) {
    this->actorList = actorList;
    this->characters = std::make_shared<CharacterView>(0,0,0, this->window);
}

void MasterView::setPlayer(std::shared_ptr<Fred> &fred) {
    player = std::make_shared<PlayerView>(this->actorList, fred, this->window);
}

void MasterView::setRoom(std::shared_ptr<Room> room) {
    characters->setCurrentRoom(room);
}

void MasterView::setExit(std::shared_ptr<Exit> exit){
    characters->setCurrentExit(exit);
}

void MasterView::update(float delta) {
    characters->update(delta);
    player->update(delta);
}
