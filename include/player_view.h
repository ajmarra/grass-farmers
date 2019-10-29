#ifndef FRED_VIEW_H
#define FRED_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.h"

class PlayerView : public View {
    private:
        sf::RenderWindow window;

    public:
        PlayerView(std::list<std::shared_ptr<Actor>> &actorList, int control, sf::RenderWindow &window);
};

#endif