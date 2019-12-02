#ifndef MASTER_LOGIC_H
#define MASTER_LOGIC_H

#include <list>
#include <memory>

#include "actor.h"
#include "room.h"
#include "fred.h"
#include "exit.h"
#include "timer.h"
#include "cheryl.h"

#include "item.h"
#include "trap.h"
#include "melee_weapon.h"
#include "range_weapon.h"
#include "health_item.h"

#include "bed.h"
#include "closet.h"

class EnemyView;
#include "portal.h"

class MasterView;

class MasterLogic {
    private: 
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Room>> roomList;
        std::list<std::shared_ptr<Room>>::iterator currentRoom;
        std::list<std::shared_ptr<Actor>> actorList;
		std::list<std::shared_ptr<Item>> itemList;
		std::list<std::shared_ptr<Enemy>> enemyQueueList;
        std::list<std::shared_ptr<Trap>> trapList;
    
        std::shared_ptr<Exit> currentExit;
    
        std::shared_ptr<Bed> bed;
    
        std::shared_ptr<Fred> fred;
    
        bool atCloset = false;
    
		//float delta;
        std::shared_ptr<Timer> timer;
		float delta;
        bool day = false;
        bool cherylSpawned = false;
        float spawnRate = 0;
        float enemyAttackTimer = 0;
        int nightCount = 1;

    public:
        bool paused = true;
        bool playing = false;
        bool options = false;
        bool winner = false;
        bool loser = false;

        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> mv);

        void startMenu(void);

        void startTutorial(void);

        void startLoser(void);

        void startPaused(void);

        void startWinner(void);

        void startDemo(void);

        void update(float delta);

		void loadInEnemies(void);
    
        bool isAtCloset(); // will be removed

        void setDay(bool day) { this->day = day; };

        std::list<std::shared_ptr<Actor>> getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> getCurrentRoom(void) { return *(this->currentRoom); };
        
        void checkCollisions(void);
        
		std::list<std::shared_ptr<Item>> getItemList(void) { return itemList; };
    
        std::shared_ptr<Timer> getTimer() { return timer; };

        int getNightCount(void) { return nightCount; };
        
        void setNightCount(int num) { this->nightCount = num; };

        void checkFred(void);
};

#endif
