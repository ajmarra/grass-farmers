#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "fred.h"
#include "enemy_view.h"
#include "timer.h"

class MasterView;
#include "room.h"
#include "exit.h"
#include "health_item.h"
#include "trap.h"

class MasterLogic {
    private:
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Actor>> actorList;
		std::list<std::shared_ptr<Item>> itemList;
		std::list<std::shared_ptr<EnemyView>> enemyViewList;
		//std::list<std::shared_ptr<Enemy>> enemyList;
        std::list<std::shared_ptr<Trap>> trapList;
        bool paused = false;
    
        bool day = true;
    
		float delta;
    
        std::shared_ptr<Room> currentRoom;
        std::shared_ptr<Exit> currentExit;
    
        std::shared_ptr<Fred> fred;
    
        std::shared_ptr<Timer> timer;

    public:
        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> &mv);

        void startDemo(void);

        void update(float delta);

		void loadInEnemies(void);

		std::shared_ptr<Fred> &getFred(void) { return fred; };

        std::list<std::shared_ptr<Actor>> &getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> getCurrentRoom();

		std::list<std::shared_ptr<Item>> &getItemList(void) { return itemList; };

		std::list<std::shared_ptr<EnemyView>> &getEnemyViewList(void) { return enemyViewList; };
    
        std::shared_ptr<Timer> getTimer() { return timer; };
};

#endif
