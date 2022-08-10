#include "mlStateTest.h"

mlStateTest::mlStateTest(mlGame* game) : mlState(game){
    trace("mlStateTest:: Initializing test state... ");
     trace("mlStateTest:: Setting things up...");

    mpPointArray = new SDL_Point[100];
    mpSpeedArray = new float[100];


    for(int i=0; i<99; i++){
        
        mpPointArray[i].x = rand() % MLWINDOW_WIDTH;
        mpPointArray[i].y = rand() % MLWINDOW_HEIGHT;
        mpSpeedArray[i] = (rand()%2)+1;
    }


    mpBackground = new mlEntity();
    mpBackground->SetImage(mlAssets::Instance()->mpBackgroundSfc);
    mpBackground->enabled = false;
    stageStack.push_back(mpBackground);


    label = new mlEntity();
    label->SetColor(0xff, 0x00, 0x00, 0xff);
    label->txtDstRect.x = 10;
    label->txtDstRect.y = 10;
    label->enabled = false;
    label->txtEnabled = true;
    stageStack.push_back(label);


    
    mpShip = new mlEntity();
    SDL_SetColorKey(mlAssets::Instance()->mpMartiansSfc, SDL_TRUE, SDL_MapRGB(mlAssets::Instance()->mpMartiansSfc->format, 0x00, 0x00, 0x00)); // TODO: Move this to  mlEntity
    mpShip->SetImage(mlAssets::Instance()->mpMartiansSfc);
    mpShip->srcRect.x = 8;
    mpShip->srcRect.y = 0;
    mpShip->srcRect.w = 16;
    mpShip->srcRect.h = 16;
    mpShip->dstRect.w = 16;
    mpShip->dstRect.h = 16;
    mpShip->scaleX = 2;
    mpShip->scaleY = 2;
    mpShip->enabled = true;
    stageStack.push_back(mpShip);



    

    pointer = new mlEntity();
    pointer->SetColor(0xff, 0xff, 0xff, 0xff);
    pointer->SetText("x");
    pointer->enabled = false;
    pointer->txtEnabled = true;
    stageStack.push_back(pointer);
}

mlStateTest::~mlStateTest(){
    trace("mlStateTest: Closing test.");
    if(stageStack.size() > 0){
        stageStack.pop_back();
    }
}

void mlStateTest::Pause(){

}

void mlStateTest::Resume(){

}

void mlStateTest::Input(){
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

            case SDL_JOYAXISMOTION:

            switch(mlInput::Instance()->event.jaxis.which){
                case 0: // One joystick
                    
                    if(mlInput::Instance()->event.jaxis.axis == 0 ){ // x axis
                        if(mlInput::Instance()->event.jaxis.value > mlInput::Instance()->jDeadZone || mlInput::Instance()->event.jaxis.value < -mlInput::Instance()->jDeadZone){
                            xValue = mlInput::Instance()->event.jaxis.value;
                        }
                    } else if(mlInput::Instance()->event.jaxis.axis == 1){ // y axis
                        if(mlInput::Instance()->event.jaxis.value > mlInput::Instance()->jDeadZone || mlInput::Instance()->event.jaxis.value < -mlInput::Instance()->jDeadZone){
                            yValue = mlInput::Instance()->event.jaxis.value;
                        }
                    }

                break;

                case 1: // Other Joystick, handle this recursively for as many
                        // controllers as needed. Do some more research on this.
                break;

                default:
                break;
            } 
                break;

            case SDL_JOYBUTTONDOWN:
                 trace("Bang\n");
                break;
            }
        }
    }


void mlStateTest::Update(){

    for(int i=0; i < 99; i++){
        mpPointArray[i].y += (mpSpeedArray[i]*100)*mlTime::Instance()->deltaTime;
        if(mpPointArray[i].y > MLWINDOW_HEIGHT){
            mpPointArray[i].y = 0;
            mpPointArray[i].x = rand()%MLWINDOW_WIDTH;
        } 
    }

    //sprintf(debugString, "XPOS: %d YPOS: %d", yValue, xValue);
    //sprintf(debugString, "x: %d, y: %d", xValue, yValue);
    //label->SetText(debugString);

    // Pointer
    mpShip->dstRect.x = mlUtilities::Instance()->MapRange((int)-32768, (int)32768, 0, MLWINDOW_WIDTH, xValue)-8;
    mpShip->dstRect.y = mlUtilities::Instance()->MapRange((int)-32768, (int)32768, 0, MLWINDOW_HEIGHT, yValue)-8;
}


void mlStateTest::Draw(){
    if(stageStack.empty()) return;

    SDL_SetRenderDrawColor(mlGraphics::Instance()->mpRenderer, 0xff, 0x00, 0xff, 0xff);

    SDL_RenderDrawPoints(mlGraphics::Instance()->mpRenderer, mpPointArray, 99);

    for(int i=0; i<stageStack.size(); i++){
        stageStack[i]->Draw();
    }  
}