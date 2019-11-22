#include "master_view.h"
#include "master_logic.h"

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> &window) {
    this->window = window;
}

void MasterView::init(std::shared_ptr<MasterLogic> &logic) {
    this->logic = logic;
}

void MasterView::setPlayer(std::shared_ptr<Fred> &fred) {
    player = std::make_shared<PlayerView>(this->logic, fred, this->window);
}

void MasterView::update(float delta) {
    player->update(delta);
	for (std::list<std::shared_ptr<EnemyView>>::iterator it = this->enemies.begin(); it != enemies.end(); it++) {
		std::shared_ptr<EnemyView> curActor = (*it);
		curActor->update(delta);
	}
}