#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "fred.h"

#include "master_view.h"

class MasterView;

class MasterLogic {
    private:
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Actor>> actorList;
        bool paused = false;

    public:
        MasterLogic(void);

        void init(std::shared_ptr<MasterView> &mv);

        void startDemo(void);

        void update(float delta);

        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
};

#endif