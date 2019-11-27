#ifndef ENEMY_VIEW_H
#define ENEMY_VIEW_H

#include <list>
#include <memory>

#include "view.h"
#include "enemy.h"
#include "fred.h"
#include "room.h"

class EnemyView : View {
	private:
		std::shared_ptr<Enemy> enemy;
		float elapsedTime = 0;

		void findFred(float delta);

	public:
		EnemyView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Enemy> enemy);

		void update(float delta);
};

#endif