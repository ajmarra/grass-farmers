#include "master_logic.h"

MasterLogic::MasterLogic(void) {
    
}

void MasterLogic::init(void) {
    
}

void MasterLogic::update(float delta) {
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin();
            it != actorList.end(); it++)
            (*it)->update(delta);
    }
}