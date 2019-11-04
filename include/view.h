#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <memory>

#include "actor.h"

#include "master_logic.h"

class View {
    protected:
        std::shared_ptr<MasterLogic> logic;

    public:
        View(std::shared_ptr<MasterLogic> &logic);

        void update(float delta);
};

#endif