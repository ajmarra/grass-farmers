#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "enemy_view.h"

#include "actor.h"
#include "fred.h"
#include "range_weapon.h"
#include "melee_weapon.h"
#include "room.h"
#include "exit.h"

class MasterView;

class MasterLogic {
    private: 
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Room>> roomList;
        std::list<std::shared_ptr<Room>>::iterator currentRoom;
        std::list<std::shared_ptr<Actor>> actorList;
		std::list<std::shared_ptr<Item>> itemList;

        bool paused = false;

    public:
        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> &mv);

        void startDemo(void);

        void update(float delta);

        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> &getCurrentRoom(void) { return *(this->currentRoom); };

		std::list<std::shared_ptr<Item>> &getItemList(void) { return itemList; };

		std::list<std::shared_ptr<EnemyView>> &getEnemyViewList(void) { return enemyViewList; };
};

#endif
