#include "master_view.h"
#include "master_logic.h"

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

void MasterView::init(std::shared_ptr<MasterLogic> logic) {
    this->logic = logic;
}

void MasterView::setPlayer(std::shared_ptr<Fred> fred) {
    player = std::make_shared<PlayerView>(this->logic, fred, this->window);
}

void MasterView::switchToDay() {
    player->switchToDay();
}

void MasterView::switchToNight() {
    player->switchToNight();
}

void MasterView::update(float delta) {
    player->update(delta);
	for (std::shared_ptr<EnemyView> enemy : this->enemies) {
		enemy->update(delta);
	}
}