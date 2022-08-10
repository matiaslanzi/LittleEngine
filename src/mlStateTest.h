#ifndef mlStateTest_H
#define mlStateTest_H

#include "mlCommon.h"
#include "mlGraphics.h"
#include "mlAssets.h"
#include "mlEntity.h"
#include "mlInput.h"
#include "mlGame.h"
#include "mlState.h"
#include "mlStateGame.h"

class mlStateTest : public mlState{
public:
    mlStateTest(mlGame *game);
    ~mlStateTest();

    void Pause();
    void Resume();

    void Input();
    void Update();
    void Draw();

    std::vector<mlEntity*> stageStack;

    mlEntity*   label;
    mlEntity*   pointer;
    mlEntity*   mpBackground;
    mlEntity*   mpShip;

    char        debugString[32];
    int16_t     xValue;
    int16_t     yValue;

    SDL_Point*   mpPointArray;
    float*        mpSpeedArray;
};

#endif