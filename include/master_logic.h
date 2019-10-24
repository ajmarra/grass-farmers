#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <vector>
#include <memory>

#include "actor.h"

class MasterLogic {
    private:
        std::vector<std::unique_ptr<Actor>> actorList;
        bool paused = false;

    public:
        MasterLogic(void);

        void init(void);

        void update(void);
};

#endif