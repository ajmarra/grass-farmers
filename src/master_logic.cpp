#include "master_logic.h"
#include "master_view.h"
#include <iostream>
#include <iomanip>
#include <fstream>

#include <chrono>
#include <thread>

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
		//this->actorList.push_back(testEnemy);
		this->enemyList.push_front(testEnemy);
		//std::shared_ptr<EnemyView> testEnemyView = std::make_shared<EnemyView>(this->getFred(), testEnemy, trapList);
		//this->enemyViewList.push_back(testEnemyView);		
	}

	inFile.close();
}

void MasterLogic::startDemo(void) {
    fred = std::make_shared<Fred>(700, 500);
    
    currentRoom = std::make_shared<Room>(0, 100, 1200, 800);
    std::shared_ptr<Room> farmhouse = std::make_shared<Room>(0, 100, 400, 400);
    std::shared_ptr<Exit> fieldExit = std::make_shared<Exit>(500, 890, farmhouse);
    currentExit = fieldExit;
    
    this->actorList.push_front(fred);
    
    //this->view->setPlayer(fred);
	//this->view->setEnemies(enemyViewList);

	// Creating items to test
	std::shared_ptr<Trap> testItem = std::make_shared<Trap>(150, 150, 20, 20, fred);
	this->actorList.push_back(testItem);
	this->itemList.push_front(testItem);
    //this->trapList.push_back(testItem);
	std::shared_ptr<HealthItem> testItem1 = std::make_shared<HealthItem>(250, 250, 20, 20, fred);
	this->actorList.push_back(testItem1);
	this->itemList.push_back(testItem1);
	//std::shared_ptr<Item> testItem2 = std::make_shared<Item>(ActorType::WEAPON, 350, 350, 20, 20, 1, false);
	//this->actorList.push_back(testItem2);
	//this->itemList.push_back(testItem2);
	std::shared_ptr<HealthItem> testItem3 = std::make_shared<HealthItem>(350, 250, 20, 20, fred);
	this->actorList.push_back(testItem3);
	this->itemList.push_back(testItem3);
	//std::shared_ptr<Item> testItem4 = std::make_shared<Item>(ActorType::WEAPON, 450, 550, 20, 20, 1, false);
	//this->actorList.push_back(testItem4);
	//this->itemList.push_back(testItem4);

    this->view->setPlayer(fred);
    this->loadInEnemies();
    this->view->setEnemies(enemyViewList);
    
    currentRoom->setActorList(this->actorList);
    
	fred->setCurrentRoom(currentRoom);

    this->view->setRoom(currentRoom);
    this->view->setExit(currentExit);
    
    // Create timer object that keeps track of day/night cycle
    this->timer = std::make_shared<Timer>();
}

void MasterLogic::update(float delta) {
	this->delta = delta;
    
    if (!paused) {
        
        if (timer->update(delta)) {
            day = !day;
            
            if (day) {
                //Remove enemies from actor list
                
                //Switch to day theme
                this->view->switchToDay();
            }
            
            else {
                //Start spawning enemies
                if (enemyList.size() > 0) {
                    spawnRate = 5;
                    std::shared_ptr<Enemy> toSpawn;
                    toSpawn = this->enemyList.back();
                    this->actorList.push_back(toSpawn);
                    this->enemyList.remove(toSpawn);
                    std::shared_ptr<EnemyView> testEnemyView = std::make_shared<EnemyView>(this->getFred(), toSpawn, this->trapList);
                    this->enemyViewList.push_back(testEnemyView);

                    this->view->setEnemies(enemyViewList);
                    currentRoom->setActorList(this->actorList);
                }
                               
                //Switch to night theme
                this->view->switchToNight();
            }
        }

        if (!day && enemyList.size() > 0) {
            if (spawnRate <= 0 && enemyList.size() > 0) {
                spawnRate = 5;
                std::shared_ptr<Enemy> toSpawn;
                toSpawn = this->enemyList.back();
                this->actorList.push_back(toSpawn);
                this->enemyList.remove(toSpawn);
                std::shared_ptr<EnemyView> testEnemyView = std::make_shared<EnemyView>(this->getFred(), toSpawn, this->trapList);
                this->enemyViewList.push_back(testEnemyView);

                this->view->setEnemies(enemyViewList);
                currentRoom->setActorList(this->actorList);
            }
            else {
                spawnRate -= delta;
            }
        }
        
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
