#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "master_logic.h"
#include "actor.h"
#include "character.h"
#include "fred.h"

#include "view.h"
#include "enemy_view.h"
#include "player_view.h"
#include "room.h"
#include "exit.h"

class MasterView {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<MasterLogic> logic;
        std::shared_ptr<PlayerView> player;
		std::list<std::shared_ptr<EnemyView>> enemies;

    public:
        MasterView(std::shared_ptr<sf::RenderWindow> &window);

        void init(std::shared_ptr<MasterLogic> &logic);

        void setPlayer(std::shared_ptr<Fred> &fred);

        /**
         * Create a view for the new enemy from logic and add the view to the enemyview list
         */
		void addEnemy(std::shared_ptr<Enemy> &enemy) { this->enemies.emplace_back(std::make_shared<EnemyView>(this->player, enemy)); };

        void switchToDay();
    
        void switchToNight();

        void update(float delta);
};

#endif