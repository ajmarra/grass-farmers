#ifndef ENEMY_VIEW_H
#define ENEMY_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "view.h"
#include "fred.h"
#include "enemy.h"

class EnemyView : public View {
private:
	std::shared_ptr<Enemy> enemy;
	std::shared_ptr<Fred> fred;

public:
	EnemyView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<Fred> &fred, std::shared_ptr<Enemy> &enemy);


};

#endif