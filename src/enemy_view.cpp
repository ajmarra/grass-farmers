#include <list>
#include <memory>
#include <math.h>
#include "enemy_view.h"
#define PI 3.14159265

EnemyView::EnemyView(std::shared_ptr<Fred>& fred, std::shared_ptr<Enemy>& enemy, std::list<std::shared_ptr<Trap>> traps) {
	this->fred = fred;
	this->enemy = enemy;
    this->trapList = traps;
}

void EnemyView::findFred(float delta) {
	if (fred->getCurrentRoom()->getWidth() == 1200 && enemy->getHealth() > 0) {
		int x = 0, y = 0;

		if (fred->getCenterY() < enemy->getCenterY()) y -= 1;
		if (fred->getCenterX() < enemy->getCenterX()) x -= 1;
		if (fred->getCenterY() > enemy->getCenterY()) y += 1;
		if (fred->getCenterX() > enemy->getCenterX()) x += 1;

		elapsedTime += delta;

        for (std::list<std::shared_ptr<Trap>>::iterator it = trapList.begin(); it != trapList.end(); ++it) {
            if (enemy->collidesSquare(*(*it)) && (*it)->getIsSet()) {
                enemy->damage((*it)->getDamage());
                //trapList.remove((*it));
            }
        }

		if (x == 0 && y == 0 || (enemy->collidesSquare(*fred) && elapsedTime >= 2)) {
			elapsedTime = 0;
			//enemy->stop();
			fred->damage(2); //temporarily hard coded.  Will change based on enemy type?
		}
		else enemy->setDesiredDirection(rint(atan2(y, x) * 180.0 / PI + 360));
	}
    else if (enemy->getHealth() <= 0) {
        enemy->setCanMove(false);
    }
    
}

void EnemyView::update(float delta) {
	this->findFred(delta);
   
}