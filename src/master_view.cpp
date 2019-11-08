#include "master_view.h"
#include "master_logic.h"

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> &window) {
    this->window = window;
}

void MasterView::init(std::shared_ptr<MasterLogic> &logic) {
    this->logic = logic;
}

void MasterView::setPlayer(std::shared_ptr<Fred> &fred) {
    player = std::make_shared<PlayerView>(this->logic, fred, this->window);
}

void MasterView::setRoom(std::shared_ptr<Room> room) {
    player->setCurrentRoom(room);
}

void MasterView::setExit(std::shared_ptr<Exit> exit){
    player->setCurrentExit(exit);
}

void MasterView::update(float delta) {
    player->update(delta);
}
