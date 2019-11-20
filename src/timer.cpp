#include "timer.h"

Timer::Timer() {
    this->curTimeElapsed = 0;
}

void Timer::update(float delta) {
    curTimeElapsed += delta;
    if (curTimeElapsed >= deltaLimit) {
        curTime++;
        curTimeElapsed = 0;
    }
}
