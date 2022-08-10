#include "mlParticleSystem.h"

mlParticleSystem::mlParticleSystem(){

}

mlParticleSystem::~mlParticleSystem(){
}

void mlParticleSystem::Input(){

}

void mlParticleSystem::Update(){

}

void mlParticleSystem::Draw(){
    SDL_RenderDrawPoint(mlGraphics::Instance()->mpRenderer, 1, 1);
}
