#ifndef MLPLAYER_H
#define MLPLAYER_H

#include "mlCommon.h"
#include "mlEntity.h"



class mlPlayer : public mlEntity{
public:

    mlPlayer();
    ~mlPlayer();

    void Update();
    void Draw();

    void MoveLeft();
    void MoveRight();

    bool isShooting;

private:
    mlEntity* mpCanonFlash;

};

#endif /* MLPLAYER_H */