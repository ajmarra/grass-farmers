#include "master_logic.h"
#include "master_view.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void MasterLogic::init(std::shared_ptr<MasterView> &view) {
    this->view = view;
}

void MasterLogic::loadInEnemies(void) {
	std::ifstream inFile;
	double x, y, mass, maxSpeed, maxHealth;

	inFile.open("../resources/enemies.txt");
	if (!inFile) {
		std::cout << "Unable to open enemies.txt";
		exit(1);
	}

	while (inFile >> x >> y >> mass >> maxSpeed >> maxHealth) {
		std::shared_ptr<Enemy> testEnemy = std::make_shared<Enemy>(x, y, mass, maxSpeed, maxHealth);
		this->actorList.push_back(testEnemy);
		this->enemyList.push_back(testEnemy);
		std::shared_ptr<EnemyView> testEnemyView = std::make_shared<EnemyView>(this->getFred(), testEnemy);
		this->enemyViewList.push_back(testEnemyView);

	}

	inFile.close();
}

void MasterLogic::startDemo(void) {
    fred = std::make_shared<Fred>(50, 50);
    
    currentRoom = std::make_shared<Room>(0, 100, 1200, 800);
    std::shared_ptr<Room> farmhouse = std::make_shared<Room>(0, 100, 400, 400);
    std::shared_ptr<Exit> fieldExit = std::make_shared<Exit>(500, 890, farmhouse);
    currentExit = fieldExit;
    
    this->actorList.push_front(fred);

	this->loadInEnemies();

	/* Creating test enemy
	std::shared_ptr<Enemy> testEnemy1 = std::make_shared<Enemy>(200, 200, 40, 100, 100);
	this->actorList.push_back(testEnemy1);
	std::shared_ptr<EnemyView> testEnemyView1 = std::make_shared<EnemyView>(fred, testEnemy1);
	this->enemyViewList.push_back(testEnemyView1); */

    
    this->view->setPlayer(fred);
	this->view->setEnemies(enemyViewList);

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
    
	fred->setCurrentRoom(currentRoom);

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
                    currentExit->setXY((currentRoom->getX() + currentRoom->getWidth())/2, currentRoom->getY() + currentRoom->getHeight() - 10);
                    curActor->setXY(currentExit->getX(), currentExit->getY() - currentExit->getHeight() - 100);
                    
                    curList = currentRoom->getActorList();
                    curList.push_back(curActor);
                    
                    for (int i = 0; i < 4; i++) {
                        if (tempInventory[i] != nullptr) {
                            curList.push_back(tempInventory[i]);
                        }
                    }

                    curFred->setSelected(prevSelectedIndex);
                    currentRoom->setActorList(curList);
                    
					curFred->setCurrentRoom(currentRoom);

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
