#include "master_logic.h"

MasterLogic::MasterLogic(void) {
    
}

void MasterLogic::init(std::shared_ptr<MasterView> &view) {
    this->view = view;
}

void MasterLogic::startDemo(void) {
    fred = std::make_shared<Fred>(50, 50);
    
    currentRoom = std::make_shared<Room>(0, 0, 600, 600);
    std::shared_ptr<Room> farmhouse = std::make_shared<Room>(0, 0, 400, 400);
    std::shared_ptr<Exit> fieldExit = std::make_shared<Exit>(200, 200, 40, 10, currentRoom);
    currentExit = fieldExit;
    
    this->actorList.push_front(fred);
    
    this->view->setPlayer(fred);
    this->view->setRoom(currentRoom);
    this->view->setExit(currentExit);
}

void MasterLogic::update(float delta) {
    
    // Check if desired direction will cause Fred to go out of bounds
    // Don't allow him to go if true
    
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin();
            it != actorList.end(); it++)
            (*it)->update(delta);
    }
}

std::shared_ptr<Room> MasterLogic::getCurrentRoom() {
    return currentRoom;
}
