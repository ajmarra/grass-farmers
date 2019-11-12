#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <math.h>
#include "enemy_view.h"
#define PI 3.14159265

EnemyView::EnemyView(std::shared_ptr<Fred> &fred, std::shared_ptr<Enemy> &enemy) {
	this->fred = fred;
	this->enemy = enemy;
}

void EnemyView::findFred(float delta) {
	int x = 0, y = 0;

	if (fred->getCenterY() < enemy->getCenterY()) y -= 1;
	if (fred->getCenterX() < enemy->getCenterX()) x -= 1;
	if (fred->getCenterY() > enemy->getCenterY()) y += 1;
	if (fred->getCenterX() > enemy->getCenterX()) x += 1;


	if (x == 0 && y == 0 || (enemy->collidesSquare(*fred) && delta * 1000 > 2.3)) {
		enemy->stop();
		fred->damage(2); //temporarily hard coded.  Will change based on enemy type?
	}
	else enemy->setDesiredDirection(rint(atan2(y, x) * 180.0 / PI + 360));
}

void EnemyView::update(float delta) {
	this->findFred(delta);
}