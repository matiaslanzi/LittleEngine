#ifndef MLTIME_H
#define MLTIME_H

#include "mlCommon.h"

class mlTime{
public:
    static mlTime* Instance();
    ~mlTime();

    // void IncrementFrameCount();
    // void CalculateDeltaTime();
    void SetFrameFinish();
    float FrameTime();
    bool FrameTimeElapsed();

    float           skipTicks;
    Uint32          frameFinish;
    float           deltaTime;
    Uint32          frameCount;

private:
    static mlTime *instance;

    mlTime();                     // Can't be called
    //mlTime(const mlTime& orig){}; // Copy constructor private
};

#endif