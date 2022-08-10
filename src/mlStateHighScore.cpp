#include "mlStateHighScore.h"

mlStateHighScore::mlStateHighScore(mlGame *game) : mlState(game){

    Setup();
}

mlStateHighScore::~mlStateHighScore(){
    trace("mlStateHighScore: Closing score state.");
}

void mlStateHighScore::Setup(){

    trace("mlStateHighScore Setup: Setting things up...");

    pressSpace = new mlEntity();
    pressSpace->enabled = true;
    pressSpace->txtEnabled = true;

    pressSpace->color.r = 0xff;
    pressSpace->color.g = 0xff;
    pressSpace->color.b = 0xff;
    pressSpace->color.a = 0xff;

    pressSpace->txtDstRect.x = (MLWINDOW_WIDTH / 2) - (pressSpace->txtIDRect.w / 2);
    pressSpace->txtDstRect.y = (MLWINDOW_HEIGHT / 2) - (pressSpace->txtIDRect.h / 2);
    pressSpace->txtDstRect.w = 100;
    pressSpace->txtDstRect.h = 100;

    pressSpace->SetText("SCORES");

    stageStack.push_back(pressSpace);
}

void mlStateHighScore::Pause(){

}

void mlStateHighScore::Resume(){
    
}

void mlStateHighScore::Input(){
    // Prime the event once per frame
    if(mlInput::Instance()->GetInput()){
        switch (mlInput::Instance()->event.type){
            case SDL_QUIT:
                mpGame->mRunning = false;
            case SDL_KEYDOWN:
                switch(mlInput::Instance()->event.key.keysym.sym)
                { 
                    case SDLK_SPACE:
                        mpGame->mStateStack.push_back(mpGame->mpGameState);
                        break;

                    case SDLK_ESCAPE:
                        mpGame->mStateStack.pop_back();
                    break;

                    default:
                    break;
                }
                break;
            }
        }
    }


void mlStateHighScore::Update(){

    if(stageStack.empty()) return;

    for(int i=0; i<stageStack.size(); i++){
        stageStack[i]->Update();
    }
}

void mlStateHighScore::Draw(){

    if(stageStack.empty()) return;

    for(int i=0; i<stageStack.size(); i++){
        stageStack[i]->Draw();
    }    
}