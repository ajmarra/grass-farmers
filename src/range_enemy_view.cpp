#include <list>
#include <memory>
#include <math.h>
#include "view.h"
#include "enemy_view.h"
#include "range_enemy_view.h"
#include "fred.h"
#include "enemy.h"
#include "room.h"
#define PI 3.14159265

RangeEnemyView::RangeEnemyView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Enemy> enemy)
	: EnemyView(logic, enemy) { }

void RangeEnemyView::update(float delta) {
    if (this->enemy->collidesCircle(*this->logic->getCurrentRoom()->getFred(), 300)) {
        this->enemy->hardStop();
        this->enemy->useItem(this->logic->getCurrentRoom()->getFred()->getCenterX(), this->logic->getCurrentRoom()->getFred()->getCenterX());
    }
    else this->findFred();
}