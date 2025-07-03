#include "mlEntity.h"

mlEntity::mlEntity(){
    // Rects
    srcIDRect.x = srcIDRect.y = srcIDRect.w = srcIDRect.h = 0;          
    srcRect.x = srcRect.y = srcRect.w = srcRect.h = 0;              
    dstRect.x = dstRect.y = dstRect.w = dstRect.h = 0;
    scaledRect.x = scaledRect.y = scaledRect.w = scaledRect.h = 0;

    txtIDRect.x = txtIDRect.y = txtIDRect.w = txtIDRect.h = 0;
    txtSrcRect.x = txtSrcRect.y = txtSrcRect.w = txtSrcRect.h = 0;
    txtDstRect.x = txtDstRect.y = txtDstRect.w = txtDstRect.h = 0;
    txtScaledRect.x = txtScaledRect.y = txtScaledRect.w = txtScaledRect.h = 0;

    collRect.x = collRect.y = collRect.w = collRect.h = 0;
    
    //Properties
    scaleX = scaleY = 1.0f;     
    txtScaleX = txtScaleY = 1.0f; 
    color.r = color.g = color.b = color.a = 0x00;  
    colorKey.r = colorKey.g = colorKey.b = colorKey.a = 0x00;                          
    xVel = yVel = 0.0f;
    xFric = yFric = 0.0f;
    enabled = false;
    txtEnabled = false;
    
    // Containers
    image = nullptr;       
    textImage = nullptr;
    buffer = nullptr;
    
    // Strings
    SetText("ENTITY TEXT");

    // Animation
    animates = false;
    animFrames = 1;                
    animCurrentFrame = 0;                            
    animLast = mlTime::Instance()->frameCount;               
    animFrameLength = 30;
    animOffX = animOffY = 0;
    animPlayMode = LOOP;
}

mlEntity::~mlEntity(){}



void mlEntity::Input(){
    if(!enabled) return;
}

void mlEntity::Update(){
    if(!enabled) return;
    if(animates) Animate();
}

void mlEntity::Draw(){
    if(!enabled) return;

    if(image){
        scaledRect = dstRect;
        scaledRect.w = dstRect.w * scaleX;
        scaledRect.h = dstRect.h * scaleY;
        SDL_RenderCopy(mlGraphics::Instance()->mpRenderer, image, &srcRect, &scaledRect);
    }

    if(textImage && txtEnabled){
        txtScaledRect = txtDstRect;
        txtScaledRect.w = txtDstRect.w * txtScaleX;
        txtScaledRect.h = txtDstRect.h * txtScaleY;
        SDL_RenderCopy(mlGraphics::Instance()->mpRenderer, textImage, &txtSrcRect, &txtScaledRect);
    }
}

void mlEntity::SetText(std::string str){
    
    if(str.empty()) return;

    if(textImage){
        SDL_DestroyTexture(textImage);
        textImage = nullptr;
    }

    char charsStr[str.size()];
    strcpy(charsStr, str.c_str());

    buffer = TTF_RenderText_Blended(mlType::Instance()->font, charsStr, color);

    /* TODO: Research this                                                     *
     * Here is an allocation, this can be a possible snag, should probably     *
     * research what is exaclty happening when create texture from surface     *
     * gets called.                                                            *
     */

    textImage = SDL_CreateTextureFromSurface(mlGraphics::Instance()->mpRenderer, buffer);

    SDL_QueryTexture(textImage, NULL, NULL, &txtIDRect.w, &txtIDRect.h);
    txtSrcRect = txtIDRect;
    txtDstRect.w = txtSrcRect.w;
    txtDstRect.h = txtSrcRect.h;
}

void mlEntity::SetColor(int r, int g, int b, int a){
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
}

void mlEntity::SetColorKey(int r, int g, int b, int a){
    colorKey.r = r;
    colorKey.g = g;
    colorKey.b = b;
    colorKey.a = a;
}



void mlEntity::SetImage(SDL_Surface *srfc){
    image = SDL_CreateTextureFromSurface(mlGraphics::Instance()->mpRenderer, srfc);
    SDL_QueryTexture(image, NULL, NULL, &srcIDRect.w, &srcIDRect.h);
    srcRect = dstRect = srcIDRect;
}

void mlEntity::Animate(){
    if(!animates) return;
    
    /* TODO: make this frames per second instead of arbitrary frames           */
    if(mlTime::Instance()->frameCount >= animLast + animFrameLength){ 
        if(animFrames > 1){ 
            if(animCurrentFrame == animFrames){     
                if(animPlayMode == ONESHOT){
                    animCurrentFrame = 0;
                    srcRect.x = srcIDRect.x;
                    srcRect.y = srcIDRect.y;
                    enabled = false;
                }

                if(animPlayMode == LOOP){
                    animCurrentFrame = 0;
                    srcRect.x = srcIDRect.x;
                    srcRect.y = srcIDRect.y;
                }
            } else {
                // TODO: Implement rev and loop rev animation mode.
                srcRect.x = srcIDRect.x + animOffX * animCurrentFrame;
                srcRect.y = srcIDRect.y + animOffY * animCurrentFrame;
                animLast = mlTime::Instance()->frameCount;
                animCurrentFrame++;
            }
        }
    }
}