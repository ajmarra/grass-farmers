#include "master_logic.h"
#include "master_view.h"

void MasterLogic::init(std::shared_ptr<MasterView> &view) {
    this->view = view;
}

void MasterLogic::startDemo(void) {
    std::shared_ptr<Fred> fred = std::make_shared<Fred>(50, 50);
    this->actorList.push_front(fred);
    this->view->setPlayer(fred);

	// Creating items to test
	std::shared_ptr<Item> testItem = std::make_shared<Item>(ActorType::WEAPON, 150, 150, 20, 20, 1, false);
	this->actorList.push_back(testItem);
	this->itemList.push_front(testItem);
	std::shared_ptr<Item> testItem1 = std::make_shared<Item>(ActorType::WEAPON, 250, 250, 20, 20, 1, false);
	this->actorList.push_back(testItem1);
	this->itemList.push_back(testItem1);
	std::shared_ptr<Item> testItem2 = std::make_shared<Item>(ActorType::WEAPON, 350, 350, 20, 20, 1, false);
	this->actorList.push_back(testItem2);
	this->itemList.push_back(testItem2);
	std::shared_ptr<Item> testItem3 = std::make_shared<Item>(ActorType::WEAPON, 350, 250, 20, 20, 1, false);
	this->actorList.push_back(testItem3);
	this->itemList.push_back(testItem3);
	std::shared_ptr<Item> testItem4 = std::make_shared<Item>(ActorType::WEAPON, 450, 550, 20, 20, 1, false);
	this->actorList.push_back(testItem4);
	this->itemList.push_back(testItem4);
}

void MasterLogic::update(float delta) {
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin();
            it != actorList.end(); it++)
            (*it)->update(delta);
    }
}