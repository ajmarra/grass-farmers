#include "enemy_view.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <math.h>
#define PI 3.14159265

EnemyView::EnemyView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<Fred> &fred, std::shared_ptr<Enemy> &enemy)
	: View(logic) {
	this->fred = fred;
	this->enemy = enemy;
}
