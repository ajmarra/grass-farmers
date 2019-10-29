#include "view.h"

View::View(std::list<std::shared_ptr<Actor>> &actorList, int control) {
    this->actorList = actorList;
    this->control = control;
}

void View::update(float delta) {

}