#include "menu_view.h"

MenuView::MenuView(std::shared_ptr<MasterLogic> &logic,  std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
        this->window = window;
    }

void PlayerView::pollInput() {
    sf::Event Event;

}