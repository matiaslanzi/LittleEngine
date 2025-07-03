#pragma once

#include "mlCommon.h"
#include "mlGraphics.h"
#include "mlPlayer.h"
#include "mlEnemy.h"
#include "mlAssets.h"
#include "mlType.h"
#include "mlInput.h"
#include "mlTime.h"
#include "mlState.h"
#include "mlStateGame.h"
#include "mlStateSplash.h"

class mlGame{
public:
    mlGame();
    ~mlGame();

    void QuitGame();

    bool Running();

    bool        mRunning;
    
    mlState     *mpSplashState;
    mlState     *mpGameState;
    //mlState     *mpWinsState;
    //mlState     *mlLoseState;
    //mlState     *mpMenuState;
    //mlState     *mpScores;

    std::vector <mlState*>  mStateStack;
};