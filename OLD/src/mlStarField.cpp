#include "mlStarField.h"

/* @ALERT: SOME initialization and loops are hard coded, be aware!
 *   
 * This should really be a particle system, but this is a start.
 */


mlStarField::mlStarField(){

    /* @TODO: Initialize this class with parameters. */

    mStarQty = 100;
    mMaxVel = 2;
    mMinVel = 1;

    mpPointArray = new SDL_Point[mStarQty];
    mpSpeedArray = new float[mStarQty];

   for(i=0; i<mStarQty-1; i++){
        mpPointArray[i].x = rand() % MLWINDOW_WIDTH;
        mpPointArray[i].y = rand() % MLWINDOW_HEIGHT;
        mpSpeedArray[i] = (rand()%2)+1; // 2 different speeds
        /* @TODO: Implement max and min velocity*/
    }

    enabled = true;
}   

mlStarField::~mlStarField(){
    if(mpPointArray) delete mpPointArray;
    mpPointArray = nullptr;
    if(mpSpeedArray) delete mpSpeedArray;
    mpSpeedArray = nullptr;
}

void mlStarField::Input(){
    if(!enabled) return;
}

void mlStarField::Update(){
    if(!enabled) return;

    for(i=0; i < 99; i++){
        mpPointArray[i].y += (mpSpeedArray[i]*100) * mlTime::Instance()->deltaTime;
        if(mpPointArray[i].y > MLWINDOW_HEIGHT){
            mpPointArray[i].y = 0;
            mpPointArray[i].x = rand()%MLWINDOW_WIDTH;
        } 
    }
}

void mlStarField::Draw(){
    if(!enabled) return;

    SDL_SetRenderDrawColor(mlGraphics::Instance()->mpRenderer, 0xff, 0x00, 0xff, 0xff);
    SDL_RenderDrawPoints(mlGraphics::Instance()->mpRenderer, mpPointArray, 99);
}