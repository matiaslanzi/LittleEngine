#pragma once

#include "mlCommon.h"
#include "mlGraphics.h"
#include "mlPlayer.h"
#include "mlEnemy.h"
#include "mlAssets.h"
#include "mlShot.h"
#include "mlType.h"
#include "mlInput.h"
#include "mlTime.h"
#include "mlState.h"
#include "mlStateGame.h"
#include "mlStateSplash.h"
#include "mlStateMenu.h"
#include "mlStateHighScore.h"
#include "mlStateTest.h"

class mlGame{
public:
    mlGame();
    ~mlGame();

    bool Running();

    bool        mRunning;
    
    mlState     *mpSplashState;
    mlState     *mpMenuState;
    mlState     *mpGameState;
    mlState     *mpScoreState;

    std::vector <mlState*>  mStateStack;
};