/* This is the assets manager class, all assets are loaded here.
 */

#include "mlAssets.h"

// Singleton variable
mlAssets* mlAssets::instance = NULL;

// Singleton method
mlAssets* mlAssets::Instance(){
    if(instance == NULL){
        instance = new mlAssets();
    }

    return instance;
}

mlAssets::mlAssets(){
    /* TODO: Make this an assets manager.                                      *
     * Should be able to load and unload assets from memory and keep inventory *
     * eventually this class should be able to pack all assets in a preitary   *
     * file that can be enbedded in the binary in roder to have one program.   */
    
    trace("mlAssets: Loading assets...");

    // Load background
    mpBackgroundSfc = IMG_Load("spritesheet.png");
    if(mpBackgroundSfc == NULL){
        trace("mlAssets: Can't load sprite sheet file1. %s", IMG_GetError());
        exit(-1);
    }

    // Load sprite sheet
    spriteSheetSfc = IMG_Load("invadersSpritesheet.png");
    if(spriteSheetSfc == NULL){
        trace("mlAssets: Can't load sprite sheet file2. %s", IMG_GetError());
        exit(-1);
    }

    // Load player
    playerSfc = IMG_Load("spaceship.png");
    if(playerSfc == NULL){
        trace("mlAssets: Can't load image. %s", IMG_GetError());
        exit(-1);
    }   

    // Load explosions
    explosionSfc = IMG_Load("explosion256.png");
    if(explosionSfc == NULL){
        trace("mlAssets: Can't load image. %s", IMG_GetError());
        exit(-1);
    }

    planetBGSfc = IMG_Load("planetBG.png");
    if(planetBGSfc == NULL){
        trace("mlAssets: Can't load image. %s", IMG_GetError());
        exit(-1);
    }

    mpMartiansSfc = IMG_Load("martians.png");
    if(planetBGSfc == NULL){
        trace("mlAssets: Can't load image. %s", IMG_GetError());
        exit(-1);
    }
}

mlAssets::~mlAssets(){
    
}