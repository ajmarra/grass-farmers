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
    
    currentRoom->setActorList(this->actorList);
    
    this->view->setRoom(currentRoom);
    this->view->setExit(currentExit);
}

void MasterLogic::update(float delta) {
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin(); it != actorList.end(); it++) {
            std::shared_ptr<Actor> curActor = (*it);
            if (curActor != fred) {
                curActor->update(delta);
            }
            
            // Check to make sure Fred is still within the current room
            else if (curActor->liesInsideSquare((*currentRoom))) {
                
                // Check if Fred uses the exit
                if (curActor->collidesSquare((*currentExit))) {
                    std::shared_ptr<Room> temp = currentRoom;
                    currentRoom = currentExit->getDestination();
                    currentExit->setDestination(temp);
                    currentExit->setXY((currentRoom->getX() + currentRoom->getWidth())/2, currentRoom->getY() + currentRoom->getHeight() - 10);
                    curActor->setXY(currentExit->getX(), currentExit->getY() - currentExit->getHeight() - 100);
                    std::list<std::shared_ptr<Actor>> curList = currentRoom->getActorList();
                    curList.push_back(curActor);
                    currentRoom->setActorList(curList);
                    view->setRoom(currentRoom);
                    view->setExit(currentExit);
                }
                else {
                    curActor->update(delta);
                }
            }
            
            // If Fred reaches the outside of the room, push him back inside
            else if (!curActor->liesInsideSquare((*currentRoom))) {
                if (curActor->getY() < currentRoom->getY()) {
                    curActor->hardStop();
                    curActor->setXY(curActor->getX(), curActor->getY() + 1);
                }
                else if (curActor->getY() + curActor->getHeight() > currentRoom->getY() + currentRoom->getHeight()) {
                    curActor->hardStop();
                    curActor->setXY(curActor->getX(), curActor->getY() - 1);
                }
                else if (curActor->getX() < currentRoom->getX()) {
                    curActor->hardStop();
                    curActor->setXY(curActor->getX() + 1, curActor->getY());
                }
                else if (curActor->getX() + curActor->getWidth() > currentRoom->getX() + currentRoom->getWidth()) {
                    curActor->hardStop();
                    curActor->setXY(curActor->getX() - 1, curActor->getY());
                }
                else {
                    curActor->hardStop();
                    curActor->setXY(curActor->getX() - 1, curActor->getY() - 1);
                }
            }
        }
    }
}

std::shared_ptr<Room> MasterLogic::getCurrentRoom() {
    return currentRoom;
}
