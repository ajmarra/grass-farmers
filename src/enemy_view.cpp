#include <list>
#include <memory>
#include <math.h>
#include "enemy_view.h"
#include "fred.h"
#include "enemy.h"
#include "room.h"
#define PI 3.14159265

EnemyView::EnemyView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Enemy> enemy)
        :  View(logic){
	this->enemy = enemy;
}

void EnemyView::findFred(float delta) {
	if (fred->getCurrentRoom()->getWidth() == 1200 && enemy->getHealth() > 0) {
		int x = 0, y = 0;

        if (this->logic->getCurrentRoom()->getFred()->getCenterY() < this->enemy->getCenterY()) y--;
        if (this->logic->getCurrentRoom()->getFred()->getCenterX() < this->enemy->getCenterX()) x--;
        if (this->logic->getCurrentRoom()->getFred()->getCenterY() > this->enemy->getCenterY()) y++;
        if (this->logic->getCurrentRoom()->getFred()->getCenterX() > this->enemy->getCenterX()) x++;

		enemy->setDesiredDirection(rint(atan2(y, x) * 180.0 / PI + 360));
	}
    else if (enemy->getHealth() <= 0) {
        enemy->setCanMove(false);
    }
    
}

void EnemyView::update(float delta) {
	this->findFred(delta);
   
}