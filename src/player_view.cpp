#include "player_view.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

PlayerView::PlayerView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<Fred> &fred, std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
    this->fred = fred;
    this->window = window;
}

void PlayerView::pollEvents() {
    sf::Event Event;
    while (this->window->pollEvent(Event)) {
        if (Event.type == sf::Event::Closed)
            this->window->close();

        if (Event.type == sf::Event::KeyPressed) {
            switch (Event.key.code) {
                case sf::Keyboard::W:
                    fred->setDesiredDirection(270);
                    break;
                case sf::Keyboard::A:
                    fred->setDesiredDirection(180);
                    break;
                case sf::Keyboard::S:
                    fred->setDesiredDirection(90);
                    break;
                case sf::Keyboard::D:
                    fred->setDesiredDirection(0);
                    break;
            }
        }

        if (Event.type == sf::Event::KeyReleased) {
            switch (Event.key.code) {
                case sf::Keyboard::W:
                    fred->stop();
                    break;
                case sf::Keyboard::A:
                    fred->stop();
                    break;
                case sf::Keyboard::S:
                    fred->stop();
                    break;
                case sf::Keyboard::D:
                    fred->stop();
                    break;
            }
        }
    }
}

void PlayerView::drawScreen(void) {
    window->clear(sf::Color::Black);

    for (std::list<std::shared_ptr<Actor>>::iterator it = this->logic->getActorList().begin();
        it != this->logic->getActorList().end(); ++it) {
        switch ((*it)->getType()) {
            case ActorType::FRED:
                sf::RectangleShape fredShape(sf::Vector2f((*it)->getWidth(), (*it)->getHeight()));
                fredShape.setFillColor(sf::Color::White);
                fredShape.setPosition((*it)->getX(), (*it)->getY());
                this->window->draw(fredShape);
                break;
        }
    }

}

void PlayerView::update(float delta) {
    this->pollEvents();
    this->drawScreen();
}