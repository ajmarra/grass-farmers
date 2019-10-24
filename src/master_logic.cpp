
#include "master_logic.h"

MasterLogic::MasterLogic(void) {
    
}

void MasterLogic::update(void) {
    if (!paused) {
        for (int i = 0; i < actorList.size(); i++)
            actorList.at(i)->update();
    }
}