#ifndef mlStateMenu_H
#define mlStateMenu_H

#include "mlCommon.h"
#include "mlGraphics.h"
#include "mlAssets.h"
#include "mlEntity.h"
#include "mlInput.h"
#include "mlGame.h"
#include "mlState.h"

class mlGame;

class mlStateMenu : public mlState{
public:
    mlStateMenu(mlGame *game);
    ~mlStateMenu();

    void Pause();
    void Resume();

    void Input();
    void Update();
    void Draw();

    void Setup();

    std::vector<mlEntity*> stageStack;

    mlEntity    *background;
    mlEntity    *menuTitle;
    mlEntity    *playGame;
    mlEntity    *options;
    mlEntity    *highScores;
    mlEntity    *exitGame;
    
private:
};

#endif