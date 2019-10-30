#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <memory>

#include "actor.h"

class View {
    protected:
        std::list<std::shared_ptr<Actor>> actorList;

    public:
        View(std::list<std::shared_ptr<Actor>> &actorList);

        void update(float delta);
};

#endif