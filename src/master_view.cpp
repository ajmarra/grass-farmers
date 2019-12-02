#include "master_view.h"
#include "master_logic.h"
#include <iostream>

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

void MasterView::init(std::shared_ptr<MasterLogic> logic) {
    this->logic = logic;
}

void MasterView::setPlayer(std::shared_ptr<Fred> fred) {
    player = std::make_shared<PlayerView>(this->logic, fred, this->window);
}

void MasterView::addEnemy(std::shared_ptr<Enemy> enemy) {
    if (enemy->getSelectedItem() && enemy->getSelectedItem()->getType() == ActorType::RANGEWEAPON) {
        this->rangeEnemies.emplace_back(std::make_shared<RangeEnemyView>(this->logic, enemy));
    }
    else this->enemies.emplace_back(std::make_shared<EnemyView>(this->logic, enemy));
}

void MasterView::setMenu() {
    menu = std::make_shared<MenuView>(this->logic, this->window);
}

void MasterView::setPaused() {
    paused = std::make_shared<PausedView>(this->logic, this->window);
}

void MasterView::setTutorial() {
    tutorial = std::make_shared<TutorialView>(this->logic, this->window);
}

void MasterView::setLoser() {
    loser = std::make_shared<LoserView>(this->logic, this->window);
}

void MasterView::setWinner() {
    winner = std::make_shared<WinnerView>(this->logic, this->window);
}

void MasterView::switchToDay() {
    player->switchToDay();
}

void MasterView::switchToNight() {
    player->switchToNight();
}

void MasterView::update(float delta) {
    if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == false)) {
        menu->update(delta);
    }
    else if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == true) && (this->logic->loser == false) && (this->logic->winner == false)) {
        tutorial->update(delta);
    }

    else if ((this->logic->paused == true) && (this->logic->playing == true) && (this->logic->options == false)) {
        paused->update(delta);
    }

    else if ((this->logic->paused == false) && (this->logic->playing == true) && (this->logic->options == false)) {
        player->update(delta);
        for (std::shared_ptr<EnemyView> enemy : this->enemies) enemy->update(delta);
        for (std::shared_ptr<RangeEnemyView> rangeEnemy : this->rangeEnemies) rangeEnemy->update(delta);
    }

    else if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == true) && (this->logic->loser == true)) {
        loser->update(delta);
    }
    else if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == true) && (this->logic->winner == true)) {
        winner->update(delta);
    }

}



