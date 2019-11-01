#include "master_logic.h"

MasterLogic::MasterLogic(void) {
    
}

void MasterLogic::init(std::shared_ptr<MasterView> &view) {
    this->view = view;
}

void MasterLogic::startDemo(void) {
    std::shared_ptr<Fred> fred = std::make_shared<Fred>(50, 50);
    currentRoom = std::make_shared<Room>(400, 400, 400, 400);
    this->actorList.push_front(fred);
    this->view->setPlayer(fred);
    this->view->setRoom(currentRoom);
}

void MasterLogic::update(float delta) {
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin();
            it != actorList.end(); it++)
            (*it)->update(delta);
    }
}

std::shared_ptr<Room> MasterLogic::getCurrentRoom() {
    return currentRoom;
}
