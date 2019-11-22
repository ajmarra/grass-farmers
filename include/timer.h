#ifndef timer_h
#define timer_h

class Timer {
public:
    Timer();
    bool update(float delta);
    float getCurTime() { return curTime; }
    void switchCycle();
    
private:
    float curTimeElapsed;
    float curTime;
    float deltaLimit;
    float const dayDeltaLimit = 0.5;
    float const nightDeltaLimit = 1;
    float const totalTimeLimit = 360;
};

#endif
