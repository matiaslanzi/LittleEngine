#ifndef MLSHOT_H
#define MLSHOT_H

#include "mlEntity.h"

class mlShot : public mlEntity{
public:
    mlShot();
    ~mlShot();

    void Input();
    void Update();
    void Draw();

private:
};

#endif /* MLSHOT_H */
