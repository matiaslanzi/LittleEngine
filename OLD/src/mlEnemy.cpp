#include "mlEnemy.h"
#include "mlTime.h"
#include "mlGraphics.h"

mlEnemy::mlEnemy(){
    trace("mlEnemy: Initializing enemy");
}

mlEnemy::~mlEnemy(){
}

void mlEnemy::Input(){
    if(!enabled) return;
}

void mlEnemy::Update(){
    if(!enabled) return;
    
    dstRect.y += (yVel * mlTime::Instance()->deltaTime);
    dstRect.x += (xVel * mlTime::Instance()->deltaTime);

    mlEntity::Update();
}

void mlEnemy::Draw(){
    if(!enabled) return;
    mlEntity::Draw();
    //SDL_RenderCopy(mlGraphics::Instance()->mpRenderer, image, &srcRect, &dstRect);
}