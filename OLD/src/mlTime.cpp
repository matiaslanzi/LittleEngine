#include "mlTime.h"

// Singleton instance variable
mlTime* mlTime::instance = NULL;

// Singleton method
mlTime* mlTime::Instance(){
    if (instance == NULL){
        instance = new mlTime();
    }
    return instance;
}

mlTime::mlTime(){
    trace("mlTime: Initilizing time class...");
    skipTicks = MLFRAME_RATE;
    frameFinish = SDL_GetTicks();
    deltaTime = 0;
    frameCount = 1;
}

mlTime::~mlTime(){
    trace("mlTime: Killing time");
}

void mlTime::SetFrameFinish(){
    frameFinish = SDL_GetTicks();
}

float mlTime::FrameTime(){
    return frameFinish + skipTicks;
}

bool mlTime::FrameTimeElapsed(){
/* This function returns true if the skipTicks period has elapsed.
 * The main loop depends on this time to execute. Then it updates 
 * frameCount and deltaTime, very useful pieces of information for
 * the game timing. */

    if(SDL_GetTicks() > FrameTime()){

        frameCount++;
        deltaTime = (SDL_GetTicks() - frameFinish) * 0.001f;  // Milliseconds
        
        return true;
    }

    return false;
}