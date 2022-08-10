#include "mlGame.h"

mlGame::mlGame()
    : mRunning(false)
{

    mlGraphics::Instance();     // Initializes SDL, window and renderer
    mlTime::Instance();         // Initialize time
    mlAssets::Instance();       // Load the assets TODO: make this lazy
    mlInput::Instance();        // Initialize input
    

    // Instantiate the states of the game
    trace("mlGame: Loading states...");

    mpSplashState = new mlStateSplash(this);
    mpMenuState = new mlStateMenu(this);
    mpGameState = new mlStateGame(this);
    mpScoreState = new mlStateHighScore(this);
    
    mStateStack.push_back(mpSplashState);
    
    mRunning = true;
    trace("mlGame: Program running...");
}

mlGame::~mlGame(){
    trace("mlGame: closing game");

    if(mpSplashState) delete mpSplashState;
    if(mpGameState) delete mpGameState;
    if(mpMenuState) delete mpMenuState;
    if(mpScoreState) delete mpScoreState;

    trace("mlGame: Game closed");
}


/* This is the main game loop */
bool mlGame::Running(){

    if(mlTime::Instance()->FrameTimeElapsed()){
        if(mStateStack.empty()){
            trace("mlGame: State stack is empty, quitting now.");
            mRunning = false;
        } else {

            mStateStack.back()->Input();

            if(!mStateStack.empty()){ // In case input empties the stack

                mStateStack.back()->Update();
                
                mlGraphics::Instance()->ClearScreen();
                mStateStack.back()->Draw();
                mlGraphics::Instance()->FlipBuffer();
            }
        }

        mlTime::Instance()->SetFrameFinish();
    }

    SDL_Delay(1);

    return mRunning;
}