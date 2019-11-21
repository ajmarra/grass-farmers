#include "master_view.h"
#include "master_logic.h"
#include <iostream>

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> &window) {
    this->window = window;
}

void MasterView::init(std::shared_ptr<MasterLogic> &logic) {
    this->logic = logic;
}

void MasterView::setPlayer(std::shared_ptr<Fred> &fred) {
    player = std::make_shared<PlayerView>(this->logic, fred, this->window);
}

void MasterView::setMenu(){
    menu = std::make_shared<MenuView>(this->logic, this->window);
}

void MasterView::setTutorial(){
    //std::cout << "HI" << std::endl;
    tutorial = std::make_shared<TutorialView>(this->logic, this->window);
}

void MasterView::setRoom(std::shared_ptr<Room> room) {
    player->setCurrentRoom(room);
}

void MasterView::setExit(std::shared_ptr<Exit> exit){
    player->setCurrentExit(exit);
}

void MasterView::update(float delta) {
    if( (logic->paused == true) && (logic->playing == false) && (logic ->options == false)){
        //std::cout << "HI" << std::endl;
    
        menu->update(delta);
     }
    else if ((logic->paused == true) && (logic->playing == false) && (logic ->options == true)){
        //std::cout << "HULLO" << std::endl;
        tutorial->update(delta);
    }

    // else if ( (logic->paused == true) && (logic->playing == true) && (logic ->options == false)){
    //     //std::cout << "HULLO" << std::endl;
    //     tutorial->update(delta);
    // }

    else if ( (logic->paused == false) && (logic->playing == true)){
        //delete &menu;
        player->update(delta);
	    for (std::list<std::shared_ptr<EnemyView>>::iterator it = this->enemies.begin(); it != enemies.end(); it++) {
		std::shared_ptr<EnemyView> curActor = (*it);
		curActor->update(delta);
   }	
   }}



