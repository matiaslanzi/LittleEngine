#include "mlPlayer.h"
#include "mlGraphics.h"
#include "mlTime.h"
#include "mlAssets.h"

mlPlayer::mlPlayer(){
    trace("mlPlayer: Initializing the player");

    SDL_SetColorKey(mlAssets::Instance()->mpMartiansSfc, SDL_TRUE, SDL_MapRGB(mlAssets::Instance()->mpMartiansSfc->format, 0x00, 0x00, 0x00)); // TODO: Move this to  mlEntity
    image = SDL_CreateTextureFromSurface(mlGraphics::Instance()->mpRenderer, mlAssets::Instance()->mpMartiansSfc);

    enabled = true;
    yFric = 0.0f;
    xFric = 3.0f;

    srcRect = {8,0,16,16};
    srcIDRect = {8,0,16,16};
    dstRect = {MLWINDOW_WIDTH / 2,204,16,16};

    xVel = yVel = 0;

    animates = false;
    animFrames = 2;
    animFrameLength = 10;
    animOffX = 0;
    animOffY = 46;

    // Canon flash
    mpCanonFlash = new mlEntity();
    SDL_SetColorKey(mlAssets::Instance()->mpMartiansSfc, SDL_TRUE, SDL_MapRGB(mlAssets::Instance()->mpMartiansSfc->format, 0x00, 0x00, 0x00)); // TODO: Move this to  mlEntity
    mpCanonFlash->image = SDL_CreateTextureFromSurface(mlGraphics::Instance()->mpRenderer, mlAssets::Instance()->mpMartiansSfc);
    mpCanonFlash->srcRect = {0,0,8,8};
    mpCanonFlash->srcIDRect = {0,0,8,8};
    mpCanonFlash->dstRect = {64,64,8,8};
    mpCanonFlash->enabled = false;
    mpCanonFlash->animates = true;
    mpCanonFlash->animPlayMode = ONESHOT;
    mpCanonFlash->animFrames = 3;
    mpCanonFlash->animFrameLength = 2;
    mpCanonFlash->animCurrentFrame = 0;
    mpCanonFlash->animOffY = 8;
    
}

mlPlayer::~mlPlayer(){
    trace("mlPlayer: Cleaning up player");
}


void  mlPlayer::Update(){
    if(!enabled) return;

    Animate();
    // Move the player
    dstRect.y += (yVel * mlTime::Instance()->deltaTime);
    dstRect.x += (xVel * mlTime::Instance()->deltaTime);

    if(isShooting){     
        mpCanonFlash->enabled = true;
        
        mpCanonFlash->animCurrentFrame = 0;
        isShooting = false;
    }

    mpCanonFlash->dstRect.x = dstRect.x + 4;
    mpCanonFlash->dstRect.y = dstRect.y - 4;
    mpCanonFlash->Animate();
    
    // Keep the player in the screen
    if(dstRect.x >= (MLWINDOW_WIDTH - dstRect.w)){
        xVel = -100;  
        dstRect.x = (MLWINDOW_WIDTH - dstRect.w - 1);
    } 

    if(dstRect.x <= 0){
        xVel = 100;
        dstRect.x = 1;
    }

    //Side friction
    if(xVel > 0){
        xVel += -xFric*100*mlTime::Instance()->deltaTime;
    }

    if(xVel < 0){
        xVel += xFric*100*mlTime::Instance()->deltaTime;
    }

    
}

void mlPlayer::Draw(){
    mlEntity::Draw();
    mpCanonFlash->Draw();
}


void mlPlayer::MoveLeft(){
    if(xVel > 100){
        xVel = 0;
    }

    xVel += -100;
}

void mlPlayer::MoveRight(){
    if(xVel <  -100){
       xVel = 0;
    }
    xVel += 100;

}