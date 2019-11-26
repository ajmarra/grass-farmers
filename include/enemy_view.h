#ifndef ENEMY_VIEW_H
#define ENEMY_VIEW_H

#include <list>
#include <memory>

#include "enemy.h"
#include "fred.h"
#include "trap.h"

class EnemyView {
private:
	std::shared_ptr<Fred> fred;
	std::shared_ptr<Enemy> enemy;
    std::list<std::shared_ptr<Trap>> trapList;
	float elapsedTime = 0;

    void findFred(float delta);

public:
	EnemyView(std::shared_ptr<Fred> fred, std::shared_ptr<Enemy> enemy, std::list<std::shared_ptr<Trap>> trapList);

    void update(float delta);
};

#endif
