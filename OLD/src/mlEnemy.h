#ifndef MLENEMY_H
#define MLENEMY_H

#include "mlCommon.h"
#include "mlEntity.h"
#include "math.h"

class mlEnemy : public mlEntity{
public:

    mlEnemy();
    ~mlEnemy();

    void Input();
    void Update();
    void Draw();

private:
};

#endif /* MLENEMY_H */