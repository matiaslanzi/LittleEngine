#ifndef MLSTATE_H
#define MLSTATE_H

#include "mlCommon.h"

class mlGame;

class mlState{
public:

    mlState(mlGame* game) : mpGame(game){};
    virtual ~mlState(){};
    
    virtual void Reset() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void Input() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    mlGame  *mpGame;

};

#endif
