#include "master_logic.h"

MasterLogic::MasterLogic(void) {
    
}

void MasterLogic::init(void) {
    
}

void MasterLogic::update(float dt) {
    if (!paused) {
        for (int i = 0; i < actorList.size(); i++)
            actorList.at(i)->update();
    }
}