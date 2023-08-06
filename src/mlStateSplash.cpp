#include "mlStateSplash.h"

mlStateSplash::mlStateSplash(mlGame *game) : mlState(game){

    Setup();
}

mlStateSplash::~mlStateSplash(){
    trace("mlStateSplash::~mlStateSplash: Closing splash state.");
}

void mlStateSplash::Setup(){

    trace("mlStateSplash::Setup: Setting things up...");

    // Press space
    pressSpace = new mlEntity();
    pressSpace->SetColor(0xff, 0x00, 0x00, 0xff);
    pressSpace->SetText("Press space to play and escape to quit");
    pressSpace->txtDstRect.x = (MLWINDOW_WIDTH / 2) - (pressSpace->txtIDRect.w / 2);
    pressSpace->txtDstRect.y = (MLWINDOW_HEIGHT / 2) - (pressSpace->txtIDRect.h / 2);
    pressSpace->enabled = true;
    pressSpace->txtEnabled = true;
    stageStack.push_back(pressSpace);
}

void mlStateSplash::Reset(){

}

void mlStateSplash::Pause(){

}

void mlStateSplash::Resume(){
    
}

void mlStateSplash::Input(){

    if(mlInput::Instance()->GetInput()){
        switch (mlInput::Instance()->event.type){
            case SDL_QUIT:
                mpGame->QuitGame();
                break;

            case SDL_KEYDOWN:
                switch(mlInput::Instance()->event.key.keysym.sym)
                { 
                    case SDLK_SPACE:
                        mpGame->mStateStack.push_back(mpGame->mpGameState);
                        mpGame->mStateStack.back()->Reset();
                        break;

                    case SDLK_ESCAPE:
                        mpGame->mStateStack.pop_back();
                        break;

                    default:
                        break;
                }
                break;

            case SDL_JOYBUTTONDOWN:
                mpGame->mStateStack.push_back(mpGame->mpGameState);
                break;
            }
        }
    }


void mlStateSplash::Update(){

    if(stageStack.empty()) return;

    for(int i=0; i<stageStack.size(); i++){
        stageStack[i]->Update();
    }
}

void mlStateSplash::Draw(){

    if(stageStack.empty()) return;

    for(int i=0; i<stageStack.size(); i++){
        stageStack[i]->Draw();
    }    
}