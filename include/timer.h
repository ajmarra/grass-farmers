#ifndef timer_h
#define timer_h

// Controls the passage of time in the game
class Timer {
public:
    Timer();
    bool update(float delta);
    float getCurTime() { return curTime; }
    void switchCycle();
    void setCurTime(float time) { curTime = time; };
    
private:
    float curTimeElapsed;
    float curTime;
    float deltaLimit;
    float const dayDeltaLimit = 0.5;
    float const nightDeltaLimit = 1;
    float const totalTimeLimit = 360;
};

#endif
