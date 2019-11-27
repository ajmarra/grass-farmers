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

class MasterView;

class MasterLogic {
    private: 
        std::shared_ptr<MasterView> view;
        std::list<std::shared_ptr<Room>> roomList;
        std::list<std::shared_ptr<Room>>::iterator currentRoom;
        std::list<std::shared_ptr<Actor>> actorList;
		std::list<std::shared_ptr<Item>> itemList;

		float delta;

        std::list<std::shared_ptr<Trap>> trapList;
    
        bool day = true;
    
		//float delta;
        std::shared_ptr<Timer> timer;

    public:
        bool paused = true;
        bool playing = false;
        bool options = false;
        MasterLogic(void) { };

        void init(std::shared_ptr<MasterView> mv);

        void startMenu(void);

        void startTutorial(void);

        void startPaused(void);

        void startDemo(void);

        void update(float delta);

		void loadInEnemies(void);

        std::list<std::shared_ptr<Actor>> getActorList(void) { return actorList; };
    
        std::shared_ptr<Room> getCurrentRoom(void) { return *(this->currentRoom); };

		std::list<std::shared_ptr<Item>> getItemList(void) { return itemList; };
    
        std::shared_ptr<Timer> getTimer() { return timer; };
};

#endif
