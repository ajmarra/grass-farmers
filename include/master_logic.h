#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "room.h"
#include "fred.h"
#include "exit.h"
#include "timer.h"

#include "item.h"
#include "trap.h"
#include "melee_weapon.h"
#include "range_weapon.h"
#include "health_item.h"
#include "portal.h"

class MasterView;

class MasterLogic {
    private: 
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Room>> roomList;
        std::list<std::shared_ptr<Room>>::iterator currentRoom;
        std::list<std::shared_ptr<Actor>> actorList;
		std::list<std::shared_ptr<Item>> itemList;
		std::list<std::shared_ptr<EnemyView>> enemyViewList;
		std::list<std::shared_ptr<Enemy>> enemyQueueList;
        std::list<std::shared_ptr<Enemy>> enemyList;
        std::list<std::shared_ptr<Trap>> trapList;
        bool paused = false;
    
        bool day = false;

        float spawnRate = 0;

        float elapsedTime = 0;

        int nightCount = 1;
    
		float delta;
        std::shared_ptr<Timer> timer;

    public:
        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> mv);

        void startDemo(void);

        void update(float delta);

		void loadInEnemies(void);

        std::list<std::shared_ptr<Actor>> getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> getCurrentRoom(void) { return *(this->currentRoom); };
        void checkCollisions(float delta);

        void removeUsedItems(void);

		std::shared_ptr<Fred> &getFred(void) { return fred; };

        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> getCurrentRoom();

		std::list<std::shared_ptr<Item>> &getItemList(void) { return itemList; };

		std::list<std::shared_ptr<Item>> getItemList(void) { return itemList; };
    
        std::shared_ptr<Timer> getTimer() { return timer; };
};

#endif
