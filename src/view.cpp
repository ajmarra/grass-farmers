#include "view.h"

View::View(std::list<std::unique_ptr<Actor>> &actorList) {
    this->actorList = actorList;
}