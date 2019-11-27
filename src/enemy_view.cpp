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
    //this->trapList = traps;
}

void EnemyView::findFred(float delta) {
    if (this->logic->getCurrentRoom()->getWidth() == 1200) {
        int x = 0, y = 0;

        if (this->logic->getCurrentRoom()->getFred()->getCenterY() < this->enemy->getCenterY()) y--;
        if (this->logic->getCurrentRoom()->getFred()->getCenterX() < this->enemy->getCenterX()) x--;
        if (this->logic->getCurrentRoom()->getFred()->getCenterY() > this->enemy->getCenterY()) y++;
        if (this->logic->getCurrentRoom()->getFred()->getCenterX() > this->enemy->getCenterX()) x++;

        elapsedTime += delta;

/**
        for (std::list<std::shared_ptr<Trap>>::iterator it = trapList.begin(); it != trapList.end(); ++it) {
            if (enemy->collidesCircle(*(*it)) && (*it)->getIsSet()) {
                enemy->damage((*it)->getDamage());
                enemy->setCanMove(false);
            }
        }
*/
		if (x == 0 && y == 0 || (enemy->collidesCircle(*this->logic->getCurrentRoom()->getFred()) && elapsedTime >= 2)) {
			elapsedTime = 0;
			//enemy->stop();
			this->logic->getCurrentRoom()->getFred()->damage(2); //temporarily hard coded.  Will change based on enemy type?
		}
		else enemy->setDesiredDirection(rint(atan2(y, x) * 180.0 / PI + 360));
	}
}

void EnemyView::update(float delta) {
    this->findFred(delta);
}