#ifndef RANGE_ENEMY_VIEW_H
#define RANGE_ENEMY_VIEW_H

#include <list>
#include <memory>

#include "view.h"
#include "enemy_view.h"
#include "enemy.h"
#include "fred.h"
#include "room.h"

class RangeEnemyView : public EnemyView {
	private:
		float elapsedTime = 0;

	public:
		RangeEnemyView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Enemy> enemy);

		void update(float delta) override;
};

#endif