#ifndef timer_h
#define timer_h

class Timer {
public:
    Timer();
    void update(float delta);
    
private:
    float curTimeElapsed;
    float curTime;
    const float deltaLimit = 15;
};

#endif
