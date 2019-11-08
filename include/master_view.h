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
#include "player_view.h"

class MasterView {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<MasterLogic> logic;
        std::shared_ptr<PlayerView> player;

    public:
        MasterView(std::shared_ptr<sf::RenderWindow> &window);

        void init(std::shared_ptr<MasterLogic> &logic);

        void setPlayer(std::shared_ptr<Fred> &fred);

        void update(float delta);
};

#endif