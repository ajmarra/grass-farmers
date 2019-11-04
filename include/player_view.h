#ifndef FRED_VIEW_H
#define FRED_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.h"
#include "fred.h"

class PlayerView : public View {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<Fred> fred;

        void pollInput(void);

        void drawScreen(void);

    public:
        PlayerView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<Fred> &fred, std::shared_ptr<sf::RenderWindow> &window);

        void update(float delta);
};

#endif