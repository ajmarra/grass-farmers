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
    this->roomList.front()->addActor(std::make_shared<Exit>(0, 430, 1));
    this->roomList.back()->addActor(std::make_shared<Exit>(500, 500, 0));

    // Add fred
    std::shared_ptr<Fred> fred = std::make_shared<Fred>(50, 50);
    this->roomList.front()->addActor(fred);
    this->view->setPlayer(fred);
}

void MasterLogic::startMenu(void){
    this->view->setMenu();
}

void MasterLogic::startTutorial(void){
    //std::cout << "HOI" << std::endl;
    this->view->setTutorial();
}

void MasterLogic::startPaused(void){
    //std::cout << "HOI" << std::endl;
    this->view->setPaused();
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
    fred = std::make_shared<Fred>(700, 500);
    
    // Creating bed for testing
//    bed = std::make_shared<Bed>(ActorType::BED, 500, 250, 100, 50, 1);
//    this->actorList.push_back(bed);
    
    this->actorList.push_front(fred);

	this->loadInEnemies();

	// Add test enemy
	std::shared_ptr<Enemy> testEnemy = std::make_shared<Enemy>(200, 200, 40, 100, 100);
	this->roomList.front()->addActor(testEnemy);
	this->view->addEnemy(testEnemy);

	// Add test items
	this->roomList.front()->addActor(std::make_shared<RangeWeapon>(this->getCurrentRoom(), 150, 150, 40, 20, 10, 2, this->getCurrentRoom()->getFred()));
	this->roomList.front()->addActor(std::make_shared<HealthItem>(250, 250, 20, 20, this->getCurrentRoom()->getFred()));
	this->roomList.front()->addActor(std::make_shared<HealthItem>(350, 250, 20, 20, this->getCurrentRoom()->getFred()));
    
    // Add bed
    this->roomList.front()->addActor(std::make_shared<Bed>(ActorType::BED, 500, 250, 100, 50, 1));
    
    // Add closet
    this->roomList.front()->addActor(std::make_shared<Closet>(ActorType::CLOSET, 600, 350, 100, 50));

    // Create timer object that keeps track of day/night cycle
    this->timer = std::make_shared<Timer>();
}

void MasterLogic::update(float delta) {
    this->delta = delta;
    if ((paused == true) && (playing == false) && (options == false)){
        //std::cout << "HELLO" << std::endl;
    }

    else if ((paused == true) && (playing == false) && (options == true)){
        //std::cout << "HELLO" << std::endl;
    }
    
    else if ((paused == true) && (playing == true) && (options == false)){
        //std::cout << "HELLO" << std::endl;
    }
    
    
    else if ((paused == false) && (playing == true) && (options == false)) {
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
        
            // Check if Fred uses the bed
            if (curActor->getType() == ActorType::BED) {
                if (this->getCurrentRoom()->getFred()->collidesSquare(*curActor)) {
                    std::shared_ptr<Bed> curBed = std::dynamic_pointer_cast<Bed>(curActor);
                    this->getCurrentRoom()->getFred()->heal(curBed->getHealAmount(), delta);
                }
            }
        }

        // Check if Fred uses an exit
        for (std::shared_ptr<Exit> exit : this->getCurrentRoom()->getExitList()) {
            if (this->getCurrentRoom()->getFred()->collidesSquare(*exit)) {
                std::list<std::shared_ptr<Room>>::iterator newRoom = this->roomList.begin();
                advance(newRoom, exit->getDestination());
                (*newRoom)->addActor(this->getCurrentRoom()->getFred());
                this->currentRoom = newRoom;
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
    }
}
