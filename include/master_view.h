#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "actor.h"

class MasterView {
    public:
        MasterView(std::list<std::unique_ptr<Actor>> &actorList, sf::RenderWindow &window);

        void update(float delta, sf::Event e);
};

#endif