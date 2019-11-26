#include <list>
#include <memory>
#include <math.h>
#include "enemy_view.h"
#define PI 3.14159265

EnemyView::EnemyView(std::shared_ptr<Fred>& fred, std::shared_ptr<Enemy>& enemy) {
	this->fred = fred;
	this->enemy = enemy;
}

void EnemyView::findFred(float delta) {
	if (fred->getCurrentRoom()->getWidth() == 1200 && enemy->getHealth() > 0) {
		int x = 0, y = 0;

		if (fred->getCenterY() < enemy->getCenterY()) y -= 1;
		if (fred->getCenterX() < enemy->getCenterX()) x -= 1;
		if (fred->getCenterY() > enemy->getCenterY()) y += 1;
		if (fred->getCenterX() > enemy->getCenterX()) x += 1;

		enemy->setDesiredDirection(rint(atan2(y, x) * 180.0 / PI + 360));
	}
    else if (enemy->getHealth() <= 0) {
        enemy->setCanMove(false);
    }
    
}

void EnemyView::update(float delta) {
	this->findFred(delta);
   
}