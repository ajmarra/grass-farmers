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
#include "player_view.h"
#include "room.h"
#include "exit.h"

class MasterView {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<MasterLogic> logic;
        std::shared_ptr<PlayerView> player; 
        std::shared_ptr<MenuView> menu;

    public:
        MasterView(std::shared_ptr<sf::RenderWindow> &window);

        void init(std::shared_ptr<MasterLogic> &logic);

        void setMenu(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window);

        void setPlayer(std::shared_ptr<Fred> &fred);

        void setRoom(std::shared_ptr<Room> room);
    
        void setExit(std::shared_ptr<Exit> exit);

        void update(float delta);
};

#endif
