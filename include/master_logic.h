#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "item.h"
#include "fred.h"
#include "range_weapon.h"
#include "melee_weapon.h"
#include "room.h"
#include "exit.h"
#include "health_item.h"

class MasterView;

class MasterLogic {
    private: 
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Room>> roomList;
        std::list<std::shared_ptr<Room>>::iterator currentRoom;
        std::list<std::shared_ptr<Actor>> actorList;
		std::list<std::shared_ptr<Item>> itemList;
		std::list<std::shared_ptr<Enemy>> enemyList;
        bool paused = false;
		float delta;

    public:
        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> &mv);

        void startDemo(void);

        void update(float delta);

		void loadInEnemies(void);

        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> &getCurrentRoom(void) { return *(this->currentRoom); };

		std::list<std::shared_ptr<Item>> &getItemList(void) { return itemList; };
};

#endif
