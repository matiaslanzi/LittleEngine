#ifndef mlStateGame_H
#define mlStateGame_H

#include "mlCommon.h"

#include "mlEntity.h"
#include "mlPlayer.h"
#include "mlInput.h"
#include "mlAssets.h"
#include "mlGraphics.h"
#include "mlTime.h"
#include "mlGame.h"
#include "mlState.h"
#include "mlStarField.h"

class mlGame;

class mlStateGame : public mlState{
public:
    mlStateGame(mlGame *game);
    ~mlStateGame();

    void Pause();
    void Resume();

    void Input();
    void Update();
    void Draw();

    void Setup();
    void Reset();

    void PlayerShoot();
    void ShotsUpdate();
    void ShotsDraw();
    void EnemyUpdate();
    void EnemyDraw();

    float   gravity;

    mlPlayer*       player;
    mlEntity*       background;
    mlEntity*       scoreLabel;
    mlEntity*       explosion;
    mlStarField*    mpStarfield;

    mlEntity*       debug;

    bool                        win;
    Uint32                      score;              // Score tally
    char                        scoreStr[12];       // String for display
    char                        debugString[32];
    std::vector<mlEntity*>      shotsPool;
    std::vector<mlEntity*>      shotsShot;
    std::vector<mlEntity*>      enemies;
    std::vector<mlEntity*>      stageStack;

    SDL_Point*   mpPointArray;
    float*        mpSpeedArray;
    
private:

    bool mbShoot;
    bool mbLeft;
    bool mbRight;
};

#endif