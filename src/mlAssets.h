/*
 * File: mlAssets.h
 * Author: @matiaslanzi
 * 
 * All assets get loaded here to be used later.
 * This class is a simple place holder to keep the assets somewhere, the class
 * does nothing to manage the assets. But it could, so that is the TODO: here.
 * 
 */

#ifndef MLASSETS_H
#define MLASSETS_H

#include "mlCommon.h"

class mlAssets{
public:
    static mlAssets* Instance();
    virtual ~mlAssets();

    SDL_Surface     *mpMartiansSfc;
    SDL_Surface     *mpBGSfc;
    
private:
    
    static mlAssets *instance;
    
    mlAssets();                             // Can't be called
    mlAssets(const mlAssets& orig){};       // Can't copy
};

#endif /* MLASSETS_H */