/*
 * File: mlEntity.h
 * Author: matiaslanzi
 * 
 * This is the entity class, this class presents basic functionality for a 
 * game object. Please note all vars and methods are public so the guts are
 * exposed. So take care of doig operations in the right order. Like setText()
 * before you calculate sizes or change color. Accesors will taka care of 
 * closing this class when the time comes. For now it's open to experimentation
 *  and search of best practices.
 */

#ifndef MLENTITY_H
#define MLENTITY_H

#include "mlCommon.h"

#include "mlGraphics.h"
#include "mlType.h"
#include "mlTime.h"

class mlEntity{
public:

    enum playMode{
        ONESHOT,
        REV,
        LOOP,
        LOOPREV
    };

    mlEntity();
    ~mlEntity();

    virtual void Input();
    virtual void Update();
    virtual void Draw();

    void SetText(std::string str);
    void SetColor(int r, int g, int b, int a);
    void SetColorKey(int r, int g, int b, int a);
    void SetImage(SDL_Surface *srfc);
    void Animate();

    SDL_Rect        srcIDRect;      // source identity
    SDL_Rect        srcRect;        // source, where we read from
    SDL_Rect        dstRect;        // where we draw to
    SDL_Rect        scaledRect;     // scale applied

    SDL_Rect        txtIDRect;      // text identity rect
    SDL_Rect        txtSrcRect;     // text source rect
    SDL_Rect        txtDstRect;     // text destination rect
    SDL_Rect        txtScaledRect;  // once scale is applied
    SDL_Rect        collRect;       // collision rect
    
    float           txtScaleX;     
    float           txtScaleY;
    float           scaleX;
    float           scaleY;
    SDL_Color       color;
    SDL_Color       colorKey;
    float           xVel;
    float           yVel;
    float           xFric;
    float           yFric;
    SDL_Texture     *image;
    SDL_Texture     *textImage;
    SDL_Surface     *buffer;
    bool            enabled;
    bool            txtEnabled;
    

    // Animation TODO: move to animation class?
    // Better make component system, mmmmm.
    bool   animates;
    Uint32 animFrames;                // How many frames this animation is made of
    Uint32 animCurrentFrame;
    Uint32 animLast;                  // Last time it was animated TODO: Make timing relative to seconds
    Uint32 animFrameLength;           // How long to show each frame in frames
    Uint32 animOffX, animOffY;        // The spritesheet offset.
    playMode animPlayMode;            // One one shoot, loop

private:
};

#endif /* MLENTITY_H */