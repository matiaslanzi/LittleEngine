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

}
// void mlTime::IncrementFrameCount(){
//     frameCount++;
// }

// void mlTime::CalculateDeltaTime(){
//     deltaTime = (SDL_GetTicks() - frameFinish) * 0.001f;  // Milliseconds
// }

void mlTime::SetFrameFinish(){
    frameFinish = SDL_GetTicks();
}

float mlTime::FrameTime(){
    return frameFinish + skipTicks;
}

bool mlTime::FrameTimeElapsed(){

    if(SDL_GetTicks() > FrameTime()){

        frameCount++;
        deltaTime = (SDL_GetTicks() - frameFinish) * 0.001f;  // Milliseconds
        
        return true;
    }

    return false;
}