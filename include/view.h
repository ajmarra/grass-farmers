#ifndef VIEW_H
#define VIEW_H

#include <list>
#include <memory>

#include "actor.h"

class View {
    protected:
        std::list<std::shared_ptr<Actor>> actorList;
        int control; //stores the spot in the list of the actor that this view is controlling
    
    public:
        View(std::list<std::shared_ptr<Actor>> &actorList, int control);

        void update(float delta);
};

#endif