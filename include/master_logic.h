#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"

class MasterLogic {
    private:
        std::list<std::unique_ptr<Actor>> actorList;
        bool paused = false;

    public:
        MasterLogic(void);

        void init(void);

        void update(float delta);

        std::list<std::unique_ptr<Actor>> &getActorList(void) { return actorList; };
};

#endif