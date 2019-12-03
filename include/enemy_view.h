#ifndef ENEMY_VIEW_H
#define ENEMY_VIEW_H

#include <list>
#include <memory>

#include "view.h"
#include "enemy.h"
#include "fred.h"
#include "room.h"

/*
* The view for all enemies.  Controls the AI so that they follow Fred or shoot at him
*/
class EnemyView : public View {
    protected:
        std::shared_ptr<Enemy> enemy;
        float elapsedTime = 0;
        void findFred(void);

    public:
        EnemyView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Enemy> enemy);

        virtual void update(float delta);
};

#endif