/* This is the assets manager class (not yes a manager)
 * for now all assets get declared and loaded here.
 * My wish is for this class to manage assets as well as packing them for 
 * production. Something like that.
 * 
 * TODO: Research loading techniques
 * TODO: figure out where to load the assets
 * TODO: create a load function
 * TODO: pack the data in binary
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
    
    trace("mlAssets: Loading assets...");

    mpMartiansSfc = IMG_Load("martians.png");
    if(mpMartiansSfc == NULL){
        trace("mlAssets: Can't load image. %s", IMG_GetError());
        exit(-1);
    }
}

mlAssets::~mlAssets(){
    
}