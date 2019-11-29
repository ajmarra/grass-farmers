#include "timer.h"

Timer::Timer() {
    this->curTimeElapsed = 0;
    this->deltaLimit = dayDeltaLimit;
}

bool Timer::update(float delta) {
    curTimeElapsed += delta;
    if (curTimeElapsed >= deltaLimit) {
        curTime += 5;
        curTimeElapsed = 0;
    }
    if (curTime >= totalTimeLimit) {
        curTime = 0;
        switchCycle();
        return true;
    }
    
    return false;
}

void Timer::switchCycle() {
    if (deltaLimit == nightDeltaLimit) {
        deltaLimit = dayDeltaLimit;
    }
    else {
        deltaLimit = nightDeltaLimit;
    }
}
