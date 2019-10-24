#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <memory>

#include "actor.h"

class View {
    protected:
        std::vector<std::unique_ptr<Actor>> actorList;
    
    public:
        View(std::vector<std::unique_ptr<Actor>> &actorList);
};

#endif