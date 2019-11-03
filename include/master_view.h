#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "actor.h"
#include "fred.h"

#include "view.h"
#include "player_view.h"
#include "character_view.h"
#include "room.h"
#include "exit.h"

class MasterView {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::list<std::shared_ptr<Actor>> actorList;
        std::shared_ptr<PlayerView> player;
        std::shared_ptr<CharacterView> characters;

    public:
        MasterView(std::shared_ptr<sf::RenderWindow> &window);

        void init(std::list<std::shared_ptr<Actor>> &actorList);

        void setPlayer(std::shared_ptr<Fred> &fred);

        void setRoom(std::shared_ptr<Room> room);
    
        void setExit(std::shared_ptr<Exit> exit);

        void update(float delta);
};

#endif
