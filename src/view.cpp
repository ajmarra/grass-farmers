#include "view.h"

View::View(std::list<std::unique_ptr<Actor>> &actorList, int controller) {
    this->actorList = actorList;
}

void View::update(float dt) {

}