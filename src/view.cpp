#include "view.h"

View::View(std::list<std::shared_ptr<Actor>> &actorList) {
    this->actorList = actorList;
}

void View::update(float delta) {

}