#include "master_logic.h"

MasterLogic::MasterLogic(void) {
    
}

void MasterLogic::init(void) {
    
}

void MasterLogic::update(float dt) {
    if (!paused) {
        for (std::list<std::unique_ptr<Actor>>::iterator it = actorList.begin;
            it != actorList.end; it++)
            (*it)->update(dt);
    }
}