#ifndef MLSTATE_H
#define MLSTATE_H

#include "mlCommon.h"

class mlGame;

class mlState{
public:

    enum gameStates{        //What's it this, I don't know, not being used but
        SPLASH_STATE,       // it kinda makes sendo for what?
        MENU_STATE,
        SCORE_STATE,
        GAME_STATE,
        WINS_TATE,
        GAMEOVER_STATE
    };

    mlState(mlGame* game) : mpGame(game){}
    virtual ~mlState(){}
    
    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void Input() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    mlGame  *mpGame;

};

#endif
