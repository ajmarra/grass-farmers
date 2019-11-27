#include "master_logic.h"
#include "master_view.h"
#include <iostream>
#include <iomanip>
#include <fstream>

#include <chrono>
#include <thread>

void MasterLogic::init(std::shared_ptr<MasterView> view) {
    this->view = view;
    
    // Create rooms
    this->roomList.push_front(std::make_shared<Room>(0, 100, 1200, 800));   // battlefield
    this->roomList.push_back(std::make_shared<Room>(0, 100, 400, 400));     // farmhouse
    this->currentRoom = roomList.begin();

    // Add exits
    this->roomList.front()->addActor(std::make_shared<Exit>(0, 430, this->roomList.begin()));
    std::list<std::shared_ptr<Room>>::iterator temp = this->roomList.end();
    this->roomList.back()->addActor(std::make_shared<Exit>(500, 500, --temp));

    // Add fred
    std::shared_ptr<Fred> fred = std::make_shared<Fred>(50, 50);
    this->roomList.front()->addActor(fred);
    this->view->setPlayer(fred);
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
		this->roomList.front()->addActor(testEnemy);
		this->view->addEnemy(testEnemy);
	}

	inFile.close();
}

void MasterLogic::startDemo(void) {
	this->loadInEnemies();
	// Add test enemy
	std::shared_ptr<Enemy> testEnemy = std::make_shared<Enemy>(200, 200, 40, 100, 100);
	this->roomList.front()->addActor(testEnemy);
	this->view->addEnemy(testEnemy);

	// Add test items
	this->roomList.front()->addActor(std::make_shared<RangeWeapon>(this->getCurrentRoom(), 150, 150, 40, 20, 10, 2, this->getCurrentRoom()->getFred()));
	this->roomList.front()->addActor(std::make_shared<HealthItem>(250, 250, 20, 20, this->getCurrentRoom()->getFred()));
	this->roomList.front()->addActor(std::make_shared<HealthItem>(350, 250, 20, 20, this->getCurrentRoom()->getFred()));

    // Create timer object that keeps track of day/night cycle
    this->timer = std::make_shared<Timer>();
}

void MasterLogic::update(float delta) {
	this->delta = delta;
    
    if (!paused) {

        // Loop throught the actor list
        for (std::shared_ptr<Actor> curActor : this->getCurrentRoom()->getActorList()) {
            curActor->update(delta);
            
            // Keep actors inside the room
            if (!curActor->liesInsideSquare(*(this->getCurrentRoom()))) {
                if (curActor->getY() < this->getCurrentRoom()->getY()) {
                    curActor->hardStop();
                    curActor->setY(curActor->getY() + 1);
                }
                if (curActor->getY() + curActor->getHeight() > this->getCurrentRoom()->getY() + this->getCurrentRoom()->getHeight()) {
                    curActor->hardStop();
                    curActor->setY(curActor->getY() - 1);
                }
                if (curActor->getX() < this->getCurrentRoom()->getX()) {
                    curActor->hardStop();
                    curActor->setX(curActor->getX() + 1);
                }
                if (curActor->getX() + curActor->getWidth() > this->getCurrentRoom()->getX() + this->getCurrentRoom()->getWidth()) {
                    curActor->hardStop();
                    curActor->setX(curActor->getX() - 1);
                }
            }
        }

        // Check if Fred uses an exit
        for (std::shared_ptr<Exit> exit : this->getCurrentRoom()->getExitList()) {
            if (this->getCurrentRoom()->getFred()->collidesSquare(*exit)) {
                this->currentRoom = exit->getDestination();
            }
        }

        if (timer->update(delta)) {
            day = !day;
            
            if (day) {
                //Remove enemies from actor list
                
                //Switch to day theme
                this->view->switchToDay();
            }
            
            else {
                //Start spawning enemies
                
                //Switch to night theme
                this->view->switchToNight();
            }
        }
        /**
        if (curActor->collidesSquare((*currentExit))) {
            std::shared_ptr<Room> temp = currentRoom;
            
            std::shared_ptr<Character> curFred = std::dynamic_pointer_cast<Character>(curActor);
            int prevSelectedIndex = curFred->getSelectedIndex();
            std::shared_ptr<Item> tempInventory[4];
            
            std::list<std::shared_ptr<Actor>> curList = this->getCurrentRoom()->getActorList();
            
            for (int i = 0; i < 4; i++) {
                curFred->setSelectedIndex(i);
                if (curFred->getSelectedItem() != nullptr) {
                    tempInventory[i] = curFred->getSelectedItem();
                    curList.remove(tempInventory[i]);
                }
            }
            
            currentRoom->setActorList(curList);
            
            curFred->setSelectedIndex(prevSelectedIndex);
            
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

            curFred->setSelectedIndex(prevSelectedIndex);
            currentRoom->setActorList(curList);
            
            curFred->setCurrentRoom(currentRoom);

            view->setRoom(currentRoom);
            view->setExit(currentExit);
        }
        */
    }
}