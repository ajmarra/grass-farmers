#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "master_logic.h"
#include "actor.h"
#include "character.h"
#include "fred.h"
#include "menu_view.h"

#include "view.h"
#include "enemy_view.h"
#include "player_view.h"
#include "tutorial_view.h"
#include "options_view.h"
#include "room.h"
#include "exit.h"

class MasterView {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<MasterLogic> logic;

        std::shared_ptr<PlayerView> player; 
        std::shared_ptr<MenuView> menu;
        std::shared_ptr<TutorialView> tutorial;
		std::list<std::shared_ptr<EnemyView>> enemies;


    public:
        MasterView(std::shared_ptr<sf::RenderWindow> &window);

        void init(std::shared_ptr<MasterLogic> &logic);

        void setMenu();

        void setTutorial();

        void setPlayer(std::shared_ptr<Fred> &fred);

		void setEnemies(std::list<std::shared_ptr<EnemyView>> enemyList) { this->enemies = enemyList; };

        void setRoom(std::shared_ptr<Room> room);
    
        void setExit(std::shared_ptr<Exit> exit);

        void update(float delta);
};

#endif
