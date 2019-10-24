#include "view.h"

View::View(std::vector<std::unique_ptr<Actor>> &actorList) {
    this->actorList = actorList;
}