#ifndef ENEMY_VIEW_H
#define ENEMY_VIEW_H

#include <list>
#include <memory>

#include "enemy.h"
#include "fred.h"

class EnemyView {
private:
	std::shared_ptr<Fred> fred;
	std::shared_ptr<Enemy> enemy;

	void findFred(float delta);

public:
	EnemyView(std::shared_ptr<Fred> &fred, std::shared_ptr<Enemy> &enemy);

	void update(float delta);
};

#endif
