#include "master_logic.h"
#include "master_view.h"

void MasterLogic::init(std::shared_ptr<MasterView> &view) {
    this->view = view;
}

void MasterLogic::startDemo(void) {
    fred = std::make_shared<Fred>(50, 50);
    
    currentRoom = std::make_shared<Room>(0, 0, 600, 600);
    std::shared_ptr<Room> farmhouse = std::make_shared<Room>(0, 0, 400, 400);
    std::shared_ptr<Exit> fieldExit = std::make_shared<Exit>(500, 590, 40, 10, farmhouse);
    currentExit = fieldExit;
    
    this->actorList.push_front(fred);
    
    this->view->setPlayer(fred);
    this->view->setRoom(currentRoom);
    this->view->setExit(currentExit);

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
    
    // Check if desired direction will cause Fred to go out of bounds
    // Don't allow him to go if true
    
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin(); it != actorList.end(); it++) {
            std::shared_ptr<Actor> curActor = (*it);
            if (curActor != fred) {
                curActor->update(delta);
            }
            else if (curActor->liesInsideSquare((*currentRoom))) {
                if (curActor->collidesSquare((*currentExit))) {
                    std::shared_ptr<Room> temp = currentRoom;
                    currentRoom = currentExit->getDestination();
                    currentExit->setDestination(temp);
                    currentExit->setXY((currentRoom->getX() + currentRoom->getWidth())/2, currentRoom->getY() + currentRoom->getHeight() - 10);
                    view->setRoom(currentRoom);
                    view->setExit(currentExit);
                    curActor->setXY(currentExit->getX(), currentExit->getY() - currentExit->getHeight() - 50);
                }
                else {
                    curActor->update(delta);
                }
            }
            else if (!curActor->liesInsideSquare((*currentRoom))) {
                if (curActor->getY() < currentRoom->getY()) {
                    fred->stop();
                    curActor->setXY(curActor->getX(), curActor->getY() + 1);
                }
                else if (curActor->getY() + curActor->getHeight() > currentRoom->getY() + currentRoom->getHeight()) {
                    fred->stop();
                    curActor->setXY(curActor->getX(), curActor->getY() - 1);
                }
                else if (curActor->getX() < currentRoom->getX()) {
                    fred->stop();
                    curActor->setXY(curActor->getX() + 1, curActor->getY());
                }
                else if (curActor->getX() + curActor->getWidth() > currentRoom->getX() + currentRoom->getWidth()) {
                    fred->stop();
                    curActor->setXY(curActor->getX() - 1, curActor->getY());
                }
                else {
                    fred->stop();
                    curActor->setXY(curActor->getX() - 1, curActor->getY() - 1);
                }
            }
        }
    }
}

std::shared_ptr<Room> MasterLogic::getCurrentRoom() {
    return currentRoom;
}
