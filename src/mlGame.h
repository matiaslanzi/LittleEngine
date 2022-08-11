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
#include "mlStateHighScore.h"

class mlGame{
public:
    mlGame();
    ~mlGame();

    bool Running();

    bool        mRunning;
    
    mlState     *mpSplashState;
    mlState     *mpGameState;

    std::vector <mlState*>  mStateStack;
};