#include "mlStateMenu.h"

mlStateMenu::mlStateMenu(mlGame *game) : mlState(game){

    Setup();
}

mlStateMenu::~mlStateMenu(){
    trace("mlStateMenu: Closing menu state.");
}

void mlStateMenu::Setup(){

    trace("mlStateMenu Setup: Setting things up...");

    const int menuYPosition = 150;
    const int menuYSpacer = 50;
    

    // Background
    background = new mlEntity();
    background->SetImage(mlAssets::Instance()->planetBGSfc);
    background->scaleX = background->scaleY = 2;
    background->enabled = true;
    stageStack.push_back(background);

    // Menu
    menuTitle = new mlEntity();
    menuTitle->SetColor(0xff, 0x00, 0x00, 0xff);
    menuTitle->SetText("MARTIANS MENU");
    menuTitle->txtDstRect.x = (MLWINDOW_WIDTH / 2) - (menuTitle->txtDstRect.w / 2);
    menuTitle->txtDstRect.y = 30;
    menuTitle->enabled = false;
    menuTitle->txtEnabled = false;
    stageStack.push_back(menuTitle);

    // Play Game
    playGame = new mlEntity();
    playGame->SetColor(0xff, 0x00, 0x00, 0xff);
    playGame->SetText("SPACE TO PLAY GAME");
    playGame->txtDstRect.x = (MLWINDOW_WIDTH / 2) - (playGame->txtDstRect.w / 2);
    playGame->txtDstRect.y = menuYPosition;
    playGame->enabled = true;
    playGame->txtEnabled = true;
    stageStack.push_back(playGame);

    // Options
    options = new mlEntity();
    options->SetColor(0xff, 0x00, 0x00, 0xff);
    options->SetText("OPTIONS");
    options->txtDstRect.x = (MLWINDOW_WIDTH / 2) - (options->txtDstRect.w / 2);
    options->txtDstRect.y = playGame->txtDstRect.y + menuYSpacer;
    options->enabled = true;
    options->txtEnabled = true;
    stageStack.push_back(options);

    // Highscore
    highScores = new mlEntity();
    highScores->SetColor(0xff, 0x00, 0x00, 0xff);
    highScores->SetText("HIGH SCORES");
    highScores->txtDstRect.x = (MLWINDOW_WIDTH / 2) - (highScores->txtDstRect.w / 2);
    highScores->txtDstRect.y = options->txtDstRect.y + menuYSpacer;
    highScores->enabled = true;
    highScores->txtEnabled = true;
    stageStack.push_back(highScores);

    // Exit game
    exitGame = new mlEntity();
    exitGame->SetColor(0xff, 0x00, 0x00, 0xff);
    exitGame->SetText("ESC TO EXIT GAME");
    exitGame->txtDstRect.x = (MLWINDOW_WIDTH / 2) - (exitGame->txtDstRect.w / 2);
    exitGame->txtDstRect.y = highScores->txtDstRect.y + menuYSpacer;
    exitGame->enabled = true;
    exitGame->txtEnabled = true;
    stageStack.push_back(exitGame);
}

void mlStateMenu::Pause(){

}

void mlStateMenu::Resume(){
    
}

void mlStateMenu::Input(){

    if(mlInput::Instance()->GetInput()){
        switch (mlInput::Instance()->event.type){
            case SDL_QUIT:
                mpGame->mRunning = false;
                break;

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


void mlStateMenu::Update(){

    if(stageStack.empty()) return;

    for(int i=0; i<stageStack.size(); i++){
        stageStack[i]->Update();
    }
}

void mlStateMenu::Draw(){

    if(stageStack.empty()) return;

    for(int i=0; i<stageStack.size(); i++){
        stageStack[i]->Draw();
    }    
}