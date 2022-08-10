#ifndef MLPARTICLESYSTEM_H
#define MLPARTICLESYSTEM_H

#include "mlCommon.h"
#include "mlGraphics.h"
#include "mlEntity.h"
#include "mlParticle.h"

class mlParticleSystem : public mlEntity{
public:
    mlParticleSystem();
    ~mlParticleSystem();

    void Input();
    void Update();
    void Draw();

private:
};

#endif