#include "master_logic.h"
#include "master_view.h"

void MasterLogic::init(std::shared_ptr<MasterView> &view) {
    this->view = view;
}

void MasterLogic::startDemo(void) {
    std::shared_ptr<Fred> fred = std::make_shared<Fred>(50, 50);
    this->actorList.push_front(fred);
    this->view->setPlayer(fred);

	std::shared_ptr<Item> testItem = std::make_shared<Item>(ActorType::WEAPON, 150, 150, 20, 20, 1, false);
	this->actorList.push_back(testItem);
	//fred->addItem(testItem);
}

void MasterLogic::update(float delta) {
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin();
            it != actorList.end(); it++)
            (*it)->update(delta);
    }
}