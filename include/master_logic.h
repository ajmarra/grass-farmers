#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "fred.h"

#include "master_view.h"

#include "room.h"
#include "exit.h"

class MasterLogic {
    private:
        std::list<std::shared_ptr<Actor>> actorList;
        std::shared_ptr<MasterView> view;
        bool paused = false;
        std::shared_ptr<Room> currentRoom;
        std::shared_ptr<Exit> currentExit;

    public:
        MasterLogic(void);

        void init(std::shared_ptr<MasterView> &mv);

        void startDemo(void);

        void update(float delta);

        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> getCurrentRoom();
};

#endif
