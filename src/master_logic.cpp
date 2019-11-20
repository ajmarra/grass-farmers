#include "master_logic.h"
#include "master_view.h"

void MasterLogic::init(std::shared_ptr<MasterView> &view) {
    this->view = view;
    
    // Create rooms
    this->roomList.push_front(std::make_shared<Room>(0, 100, 1200, 800));   //battlefield
    this->roomList.push_back(std::make_shared<Room>(0, 100, 400, 400));     //farmhouse
    this->currentRoom = roomList.begin();

    // Add exits
    this->roomList.front()->getActorList().push_back(std::make_shared<Exit>(0, 430, this->roomList.back()));
    this->roomList.back()->getActorList().push_back(std::make_shared<Exit>(500, 500, this->roomList.front()));
    
    //Add fred
    std::shared_ptr<Fred> fred = std::make_shared<Fred>(50, 50);
    this->roomList.front->getActorList().push_back(fred);
    this->view->setPlayer(fred);
}

void MasterLogic::startDemo(void) {
	// Add test enemy
	std::shared_ptr<Enemy> testEnemy = std::make_shared<Enemy>(200, 200, 40, 100, 100);
	this->roomList.front->getActorList().push_back(testEnemy);
	this->view->addEnemy(testEnemy);

	// Add test items
	std::shared_ptr<RangeWeapon> testItem = std::make_shared<RangeWeapon>(this->getCurrentRoom()->getActorList(), 150, 150, 40, 20, 10, 2);
	this->actorList.push_back(testItem);
	this->itemList.push_front(testItem);
	std::shared_ptr<RangeWeapon> testItem1 = std::make_shared<RangeWeapon>(this->getCurrentRoom()->getActorList(), 250, 250, 40, 20, 10, 2);
	this->actorList.push_back(testItem1);
	this->itemList.push_back(testItem1);
	std::shared_ptr<RangeWeapon> testItem2 = std::make_shared<RangeWeapon>(this->getCurrentRoom()->getActorList(), 350, 350, 20, 50, 10, 2);
	this->actorList.push_back(testItem2);
	this->itemList.push_back(testItem2);
	std::shared_ptr<RangeWeapon> testItem3 = std::make_shared<RangeWeapon>(this->getCurrentRoom()->getActorList(), 350, 250, 20, 50, 10, 2);
	this->actorList.push_back(testItem3);
	this->itemList.push_back(testItem3);
	std::shared_ptr<RangeWeapon> testItem4 = std::make_shared<RangeWeapon>(this->getCurrentRoom()->getActorList(), 450, 550, 40, 20, 10, 2);
	this->actorList.push_back(testItem4);
	this->itemList.push_back(testItem4);
    

    currentRoom->setActorList(this->actorList);
    currentRoom->getActorList().emplace_back(std::make_shared<Bullet>(20, 20, 2, 4, 50, 20));
    
    this->view->setRoom(currentRoom);
    this->view->setExit(currentExit);
}

void MasterLogic::update(float delta) {
    if (!paused) {
        for (std::list<std::shared_ptr<Actor>>::iterator it = actorList.begin(); it != actorList.end(); it++) {
            std::shared_ptr<Actor> curActor = *it;
            if (curActor != fred) {
                curActor->update(delta);
            }
            
            // Check to make sure Fred is still within the current room
            else if (curActor->liesInsideSquare((*currentRoom))) {
                
                // Check if Fred uses the exit
                if (curActor->collidesSquare((*currentExit))) {
                    std::shared_ptr<Room> temp = currentRoom;
                    
                    std::shared_ptr<Character> curFred = std::dynamic_pointer_cast<Character>(curActor);
                    int prevSelectedIndex = curFred->getSelectedIndex();
                    std::shared_ptr<Item> tempInventory[4];
                    
                    std::list<std::shared_ptr<Actor>> curList = currentRoom->getActorList();
                    
                    for (int i = 0; i < 4; i++) {
                        curFred->setSelected(i);
                        if (curFred->getSelectedItem() != nullptr) {
                            tempInventory[i] = curFred->getSelectedItem();
//                            for (std::list<std::shared_ptr<Actor>>::iterator newIt = curList.begin(); newIt != actorList.end(); newIt++) {
//                                std::shared_ptr<Actor> curListActor = (*newIt);
//                                if (curListActor == tempInventory[i]) {
//
//                                }
//                            }
                            curList.remove(tempInventory[i]);
                        }
                    }
                    
                    currentRoom->setActorList(curList);
                    
                    curFred->setSelected(prevSelectedIndex);
                    
                    currentRoom = currentExit->getDestination();
                    currentExit->setDestination(temp);
                    currentExit->setPos((currentRoom->getX() + currentRoom->getWidth())/2, currentRoom->getY() + currentRoom->getHeight() - 10);
                    curActor->setPos(currentExit->getX(), currentExit->getY() - currentExit->getHeight() - 100);
                    
                    curList = currentRoom->getActorList();
                    curList.push_back(curActor);
                    
                    for (int i = 0; i < 4; i++) {
                        if (tempInventory[i] != nullptr) {
                            curList.push_back(tempInventory[i]);
                        }
                    }

                    curFred->setSelected(prevSelectedIndex);
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
                    curActor->setPos(curActor->getX(), curActor->getY() + 1);
                }
                else if (curActor->getY() + curActor->getHeight() > currentRoom->getY() + currentRoom->getHeight()) {
                    curActor->hardStop();
                    curActor->setPos(curActor->getX(), curActor->getY() - 1);
                }
                else if (curActor->getX() < currentRoom->getX()) {
                    curActor->hardStop();
                    curActor->setPos(curActor->getX() + 1, curActor->getY());
                }
                else if (curActor->getX() + curActor->getWidth() > currentRoom->getX() + currentRoom->getWidth()) {
                    curActor->hardStop();
                    curActor->setPos(curActor->getX() - 1, curActor->getY());
                }
                else {
                    curActor->hardStop();
                    curActor->setPos(curActor->getX() - 1, curActor->getY() - 1);
                }
            }
        }
    }
}

std::shared_ptr<Room> MasterLogic::getCurrentRoom() {
    return currentRoom;
}
