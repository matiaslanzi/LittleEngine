#ifndef mlStateHighScore_H
#define mlStateHighScore_H

#include "mlCommon.h"
#include "mlGraphics.h"
#include "mlAssets.h"
#include "mlEntity.h"
#include "mlInput.h"
#include "mlGame.h"
#include "mlState.h"

class mlGame;

class mlStateHighScore : public mlState{
public:
    mlStateHighScore(mlGame *game);
    ~mlStateHighScore();

    void Pause();
    void Resume();

    void Input();
    void Update();
    void Draw();

    void Setup();

    std::vector<mlEntity*> stageStack;

    mlEntity    *pressSpace;
    
private:
};

#endif