#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>


#include "actor.h"
#include "fred.h"
#include "enemy_view.h"

class MasterView;
#include "room.h"
#include "exit.h"

class MasterLogic {
    private:
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Actor>> actorList;
		std::list<std::shared_ptr<Item>> itemList;
		std::list<std::shared_ptr<EnemyView>> enemyViewList;
        bool paused = false;
        std::shared_ptr<Room> currentRoom;
        std::shared_ptr<Exit> currentExit;
    
        std::shared_ptr<Fred> fred;

    public:
        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> &mv);

        void startDemo(void);

        void update(float delta);

        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> getCurrentRoom();

		std::list<std::shared_ptr<Item>> &getItemList(void) { return itemList; };

		std::list<std::shared_ptr<EnemyView>> &getEnemyViewList(void) { return enemyViewList; };
};

#endif
