#include "master_logic.h"
#include "master_view.h"

#include <iostream>
#include <iomanip>
#include <fstream>

#include <chrono>
#include <thread>

void MasterLogic::init(std::shared_ptr<MasterView> view) {
    this->view = view;
}

void MasterLogic::startMenu(void) {
    this->view->setMenu();
}

void MasterLogic::startTutorial(void) {
    //std::cout << "HOI" << std::endl;
    this->view->setTutorial();
}

void MasterLogic::startLoser(void) {
    this->view->setLoser();
}

void MasterLogic::startPaused(void) {
    //std::cout << "HOI" << std::endl;
    this->view->setPaused();
}

void MasterLogic::startWinner(void) {
    this->view->setWinner();
}

void MasterLogic::startDemo(void) {
    // Create rooms
    this->roomList.push_front(std::make_shared<Room>(0, 100, 1200, 800));   // battlefield
    this->roomList.push_back(std::make_shared<Room>(450, 200, 400, 400));     // farmhouse
    this->currentRoom = roomList.begin();

    // Add exits
    this->roomList.front()->addActor(std::make_shared<Exit>(1200, 430, 1));
    this->roomList.back()->addActor(std::make_shared<Exit>(400, 400, 0));

    // Add fred
    std::shared_ptr<Fred> fred = std::make_shared<Fred>(50, 50);
    this->roomList.front()->addActor(fred);
    this->view->setPlayer(fred);

    this->loadInEnemies();

    // test range enemies
    /**std::shared_ptr<Enemy> rangeEnemy = std::make_shared<Enemy>(555, 375, 20, 100, 100, 1);
    rangeEnemy->addItem(std::make_shared<RangeWeapon>(150, 150, 40, 20, 5, 0.1));
    this->roomList.front()->addActor(rangeEnemy);
    this->view->addEnemy(rangeEnemy);*/

    //Testing Cheryl
    /**std::shared_ptr<Cheryl> cheryl = std::make_shared<Cheryl>(500, 500, 40, 60);
    this->getCurrentRoom()->addActor(cheryl);
    this->view->addEnemy(cheryl);*/

    // Creating the portals
    std::shared_ptr<Portal> portal1 = std::make_shared<Portal>(70, 150);
    this->roomList.front()->addActor(portal1);
    std::shared_ptr<Portal> portal2 = std::make_shared<Portal>(20, 350);
    this->roomList.front()->addActor(portal2);
    std::shared_ptr<Portal> portal3 = std::make_shared<Portal>(20, 550);
    this->roomList.front()->addActor(portal3);
    std::shared_ptr<Portal> portal4 = std::make_shared<Portal>(70, 750);
    this->roomList.front()->addActor(portal4);
    
    // Add bed
    this->roomList.back()->addActor(std::make_shared<Bed>(ActorType::BED, 500, 250, 100, 50, 1));
    
    // Add closet
    this->roomList.back()->addActor(std::make_shared<Closet>(ActorType::CLOSET, 600, 350, 100, 50));

    // Add test items
    this->roomList.front()->addActor(std::make_shared<MeleeWeapon>(480, 350, 24, 60, 10, 2, this->getCurrentRoom()->getFred()));
    this->roomList.front()->addActor(std::make_shared<RangeWeapon>(150, 150, 40, 20, 40, 1));
    this->roomList.front()->addActor(std::make_shared<Trap>(650, 550, 64, 64, this->getCurrentRoom()->getFred()));
    this->roomList.front()->addActor(std::make_shared<Trap>(850, 550, 64, 64, this->getCurrentRoom()->getFred()));
    this->roomList.front()->addActor(std::make_shared<Trap>(850, 750, 64, 64, this->getCurrentRoom()->getFred()));
    this->roomList.front()->addActor(std::make_shared<HealthItem>(250, 250, 32, 32, this->getCurrentRoom()->getFred()));
    this->roomList.front()->addActor(std::make_shared<HealthItem>(350, 250, 32, 32, this->getCurrentRoom()->getFred()));
    this->roomList.front()->addActor(std::make_shared<Shield>(450, 250, 32, 32, this->getCurrentRoom()->getFred()));
    this->roomList.front()->addActor(std::make_shared<SpeedBoost>(450, 550, 64, 64, this->getCurrentRoom()->getFred()));

    // Create timer object that keeps track of day/night cycle
    this->timer = std::make_shared<Timer>();
}

void MasterLogic::loadInEnemies(void) {
    std::ifstream inFile;
    double x, y, mass, maxSpeed, maxHealth;
    int type;

    if (nightCount == 1) {
        inFile.open("../resources/enemies1.txt");
        if (!inFile) {
            std::cout << "Unable to open enemies.txt";
            exit(1);
        }

        while (inFile >> x >> y >> mass >> maxSpeed >> maxHealth >> type) {
            std::shared_ptr<Enemy> testEnemy = std::make_shared<Enemy>(x, y, mass, maxSpeed, maxHealth, type);
            this->enemyQueueList.push_front(testEnemy);
        }

        inFile.close();
    }
    else if (nightCount == 2) {
        inFile.open("../resources/enemies2.txt");
        if (!inFile) {
            std::cout << "Unable to open enemies2.txt";
            exit(1);
        }

        while (inFile >> x >> y >> mass >> maxSpeed >> maxHealth >> type) {
            std::shared_ptr<Enemy> testEnemy = std::make_shared<Enemy>(x, y, mass, maxSpeed, maxHealth, type);
            this->enemyQueueList.push_front(testEnemy);
        }

        inFile.close();
    }
    else if (nightCount == 3) {
        inFile.open("../resources/enemies3.txt");
        if (!inFile) {
            std::cout << "Unable to open enemies3.txt";
            exit(1);
        }

        while (inFile >> x >> y >> mass >> maxSpeed >> maxHealth, type) {
            std::shared_ptr<Enemy> testEnemy = std::make_shared<Enemy>(x, y, mass, maxSpeed, maxHealth, type);
            this->enemyQueueList.push_front(testEnemy);
        }

        inFile.close();
    }
    else if (nightCount == 4) {
        std::shared_ptr<Cheryl> cheryl = std::make_shared<Cheryl>(55, 375, 40, 80);
        this->getCurrentRoom()->addActor(cheryl);
        this->view->addEnemy(cheryl);
        cherylSpawned = true;
    }
}

bool MasterLogic::isAtCloset() {
    return this->atCloset;
}

void MasterLogic::checkFred(void) {
    if (this->getCurrentRoom()->getFred()->getHealth() <= 0) {
        this->paused = true;
        this->playing = false;
        this->options = true;
        this->loser = true;
        this->startLoser();
    }
    else if (this->getCurrentRoom()->getFred()->getHealth() > 0 && this->nightCount >= 4 && this->getCurrentRoom()->getEnemyList().size() <= 0) {
        if (this->cherylSpawned) {
            this->paused = true;
            this->playing = false;
            this->options = true;
            this->winner = true;
            this->startWinner();
        }
    }
}

void MasterLogic::checkCollisions(void) {
    for (std::shared_ptr<Actor> curActor : this->getCurrentRoom()->getActorList()) {
        // Keep actors inside the room
        if (curActor->getType() != ActorType::BULLET && !curActor->liesInsideSquare(*(this->getCurrentRoom()))) {
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

    // Enemies
    for (std::shared_ptr<Enemy> enemy : this->getCurrentRoom()->getEnemyList()) {
        // Trap affects
        for (std::shared_ptr<Item> it : this->getCurrentRoom()->getItemList()) {
            if (it->getType() == ActorType::TRAP && enemy->collidesSquare(*it) && !it->getCanPickUp()) {
                enemy->damage(100);
                this->getCurrentRoom()->removeActor(it);
            }
        }

        // Attack Fred
        if (enemy->collidesSquare(*(this->getCurrentRoom()->getFred())) && this->enemyAttackTimer >= 0.5 && !(this->getCurrentRoom()->getFred()->getInvincibility())) {
            enemyAttackTimer = 0;
            this->getCurrentRoom()->getFred()->damage(enemy->getDamage()); //temporarily hard coded.  Will change based on enemy type?
        }

        // Remove enemy if dead
        if (enemy->getHealth() <= 0) this->getCurrentRoom()->removeActor(enemy);
    }

    // Check if Fred uses an exit
    for (std::shared_ptr<Exit> exit : this->getCurrentRoom()->getExitList()) {
        if (this->getCurrentRoom()->getFred()->collidesSquare(*exit)) {
            std::list<std::shared_ptr<Room>>::iterator newRoom = this->roomList.begin();
            advance(newRoom, exit->getDestination());
            std::shared_ptr<Fred> fred = this->getCurrentRoom()->getFred();
            if (this->getCurrentRoom()->getFred()->getCenterX() < exit->getCenterX()) {
                fred->setPos((*newRoom)->getExitList().front()->getCenterX() + 50,
                                fred->getY());
            }
            else if (this->getCurrentRoom()->getFred()->getCenterX() > exit->getCenterX()) {
                fred->setPos((*newRoom)->getExitList().front()->getCenterX() - 100,
                                fred->getY());
            }
            this->getCurrentRoom()->removeActor(fred);
            (*newRoom)->addActor(fred);
            this->currentRoom = newRoom;
        }
    }

    // Check bullet collisions
    for (std::shared_ptr<Bullet> bullet : this->getCurrentRoom()->getBulletList()) {
        // remove if timer runs out
        if (bullet->getTimer() < 0.1) this->getCurrentRoom()->removeActor(bullet);

        // Fred
        if (this->getCurrentRoom()->getFred()->collidesSquare(*bullet)) {
            this->getCurrentRoom()->getFred()->damage(bullet->getDamage());
            this->getCurrentRoom()->removeActor(bullet);
        }

        // enemies
        for (std::shared_ptr<Enemy> enemy : this->getCurrentRoom()->getEnemyList()) {
            if (enemy->collidesSquare(*bullet)) {
                enemy->damage(bullet->getDamage());
                this->getCurrentRoom()->removeActor(bullet);
            }
        }
    }
}

void MasterLogic::update(float delta) {
    this->delta = delta;

    if ((paused == false) && (playing == true) && (options == false)) {
        this->enemyAttackTimer += delta;
        this->checkCollisions();

        this->checkFred();

        // Loop throught the actor list
        for (std::shared_ptr<Actor> curActor : this->getCurrentRoom()->getActorList()) {
            curActor->update(delta);
        
            // Check if Fred uses the bed
            if (curActor->getType() == ActorType::BED) {
                if (this->getCurrentRoom()->getFred()->collidesSquare(*curActor)) {
                    std::shared_ptr<Bed> curBed = std::dynamic_pointer_cast<Bed>(curActor);
                    this->getCurrentRoom()->getFred()->heal(curBed->getHealAmount(), delta);
                }
            }
        
            // Check if Fred is at the closet
            if (curActor->getType() == ActorType::CLOSET) {
                if (this->getCurrentRoom()->getFred()->collidesSquare(*curActor)) {
                    this->atCloset = true;
                }
                else {
                    this->atCloset = false;
                }
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
                this->loadInEnemies();

                if (enemyQueueList.size() > 0) {
                    nightCount++;
                }

                //Switch to night theme
                this->view->switchToNight();
            }
        }
        
        // spawn enemies
        if (!day && enemyQueueList.size() > 0) {
            if (spawnRate <= 0 && enemyQueueList.size() > 0) {
                if (nightCount == 1) spawnRate = 4;
                else if (nightCount == 2) spawnRate = 3;
                else if (nightCount == 3) spawnRate = 2;
                std::shared_ptr<Enemy> toSpawn;
                toSpawn = this->enemyQueueList.back();
                
                // Give enemies items
                float fireRate = float(std::rand() % 100) / 50.0 + 0.08;
                int damage = 5 * nightCount * fireRate + float(std::rand() % 5);
                switch (std::rand() % 100) {
                    case 0 ... 29:
                        toSpawn->addItem(std::make_shared<RangeWeapon>(150, 150, 40, 20, damage, fireRate));
                        break;
                    case 30 ... 39:
                        toSpawn->addItem(std::make_shared<Trap>(650, 550, 64, 64, this->getCurrentRoom()->getFred()));
                        break;
                    case 40 ... 49:
                        toSpawn->addItem(std::make_shared<HealthItem>(650, 550, 32, 32, this->getCurrentRoom()->getFred()));
                        break;
                    case 50 ... 59:
                        toSpawn->addItem(std::make_shared<Shield>(650, 550, 32, 32, this->getCurrentRoom()->getFred()));
                        break;
                    case 60 ... 69:
                        toSpawn->addItem(std::make_shared<SpeedBoost>(650, 550, 32, 32, this->getCurrentRoom()->getFred()));
                        break;
                }
                this->enemyQueueList.remove(toSpawn);
                this->view->addEnemy(toSpawn);
                this->roomList.front()->addActor(toSpawn);
            }
            else {
                spawnRate -= delta;
            }
        }
    }
}