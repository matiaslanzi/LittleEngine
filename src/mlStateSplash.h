#ifndef MLSPLASHSTATE_H
#define MLSPLASHSTATE_H

#include "mlCommon.h"
#include "mlGraphics.h"
#include "mlAssets.h"
#include "mlEntity.h"
#include "mlInput.h"
#include "mlGame.h"
#include "mlState.h"
#include "mlStateGame.h"
#include "mlParticleSystem.h"

class mlGame;

class mlStateSplash : public mlState{
public:
    mlStateSplash(mlGame *game);
    ~mlStateSplash();

    void Pause();
    void Resume();

    void Input();
    void Update();
    void Draw();

    void Setup();

    std::vector<mlEntity*> stageStack;

    mlEntity*           pressSpace;
    
private:
};

#endif
