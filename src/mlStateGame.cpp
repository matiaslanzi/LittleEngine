#include "mlStateGame.h"

mlStateGame::mlStateGame(mlGame *game) : mlState(game){

    gravity = 9.8f; // 9.80665 m/s2

    win = false;
    score = 0;

    // Player 
    player = new mlPlayer();

    // Explosion
    explosion = new mlEntity();
    SDL_SetColorKey(mlAssets::Instance()->mpMartiansSfc, SDL_TRUE, SDL_MapRGB(mlAssets::Instance()->mpMartiansSfc->format, 0x00, 0x00, 0x00)); // TODO: Move this to mlEntity
    explosion->SetImage(mlAssets::Instance()->mpMartiansSfc);
    explosion->srcIDRect = {0,32,16,16};
    explosion->srcRect = {0,32,16,16};
    explosion->dstRect = {12,12,explosion->srcRect.w,explosion->srcRect.h};
    explosion->enabled = false;

    explosion->animates = true;
    explosion->animPlayMode = explosion->ONESHOT;
    explosion->animFrameLength = 2;
    explosion->animFrames = 6;
    explosion->animOffX = 16;
    
    // Allocate the shots
    for (int i = 0; i < MLPLAYER_SHOTS_AVAILABLE; i++){
        mlEntity *shot = new mlEntity();
        shot->SetImage(mlAssets::Instance()->mpMartiansSfc);
        shot->srcIDRect.x = 8;
        shot->srcIDRect.y = 16;

        shot->srcIDRect.w = 3;
        shot->srcIDRect.h = 5;
        shot->srcRect = shot->dstRect = shot->srcIDRect;
        shot->enabled = true;
        shotsPool.push_back(shot);
    }

    // Allocate enemies
    for(int i=0; i<MLENEMY_COLUMNS; i++){
        for(int j=0; j<MLENEMY_ROWS; j++){
            mlEnemy *enemy = new mlEnemy();
            SDL_SetColorKey(mlAssets::Instance()->mpMartiansSfc, SDL_TRUE, SDL_MapRGB(mlAssets::Instance()->mpMartiansSfc->format, 0x00, 0x00, 0x00));
            enemy->SetImage(mlAssets::Instance()->mpMartiansSfc);
            enemy->srcIDRect.x = 40;
            enemy->srcIDRect.y = 0 * j;
            enemy->srcIDRect.w = 8;
            enemy->srcIDRect.h = 8;
            enemy->srcRect = enemy->dstRect = enemy->srcIDRect;
            enemy->dstRect.x = 35*i+20;
            enemy->dstRect.y = (50*j+30)*.4;
            enemy->enabled = true;
            
            enemy->animates = true;
            enemy->animFrames = 3;
            enemy->animOffX = 8;
            enemy->animFrameLength = 30;

            enemies.push_back(enemy);
        }
    }

    // Star field
    mpStarfield = new mlStarField();
    mpStarfield->enabled = true;

    // Score
    scoreLabel = new mlEntity();
    scoreLabel->SetColor(0xff, 0x99, 0x99, 0xff);
    scoreLabel->txtDstRect.x = 0;
    scoreLabel->txtDstRect.y = 0;
    scoreLabel->enabled = true;
    scoreLabel->txtEnabled = true;
    

    // Debug text
    debug = new mlEntity();
    debug->SetColor(0xff, 0x99, 0x99, 0xff);
    debug->txtDstRect.x = 200;
    debug->txtDstRect.y = 0;
    debug->enabled = true;
    debug->txtEnabled = true;

    background = new mlEntity();
    background->SetImage(mlAssets::Instance()->mpBGSfc);
    background->dstRect.w = MLWINDOW_WIDTH;
    background->dstRect.h = MLWINDOW_HEIGHT;
    background->enabled = true;
}



mlStateGame::~mlStateGame(){
    trace("mlStateGame: Closing game state.");
    // if(explosion) delete explosion;         // TODO: Fix this warning Virtual functions but no virtual destructor
    // if(mpStarfield) delete mpStarfield;     // TODO: Fix this warning Virtual functions but no virtual destructor
    // if(background) delete background;       // TODO: Fix this warning Virtual functions but no virtual destructor
    // if(scoreLabel) delete scoreLabel;       // TODO: Fix this warning Virtual functions but no virtual destructor
    // if(debug) delete debug;
}

void mlStateGame::Reset(){
    win = false;

    while(shotsShot.size()!=0){
        shotsShot.pop_back();
    }
    
    score = 0;
}

void mlStateGame::Pause(){

}

void mlStateGame::Resume(){
    
}

void mlStateGame::Input(){

    if(mlInput::Instance()->GetInput()){
        switch (mlInput::Instance()->event.type){
        case SDL_QUIT:
            mpGame->mRunning = false;
            break;
            
        case SDL_KEYDOWN:
            switch(mlInput::Instance()->event.key.keysym.sym )
            { 
                case SDLK_SPACE:
                    mbShoot = true;
                    //PlayerShoot();
                    break;

                case SDLK_LEFT:
                    mbLeft = true;
                    //player->MoveLeft();
                    break;

                case SDLK_RIGHT:
                    mbRight = true;
                    //player->MoveRight();
                    break;

                case SDLK_ESCAPE:
                    mpGame->mStateStack.pop_back();
                    break;

                default:
                    break;
            }
            break;

        case SDL_KEYUP:
            switch(mlInput::Instance()->event.key.keysym.sym )
            { 
                case SDLK_SPACE:
                    mbShoot = false;
                    //PlayerShoot();
                    break;

                case SDLK_LEFT:
                    mbLeft = false;
                    //player->MoveLeft();
                    break;

                case SDLK_RIGHT:
                    mbRight = false;
                    //player->MoveRight();
                    break;

                default:
                    break;
            }
            break;


        // case SDL_JOYAXISMOTION:    
        //     // Motion on controller 0, TODO: scan all controllers
        //     // TODO: Debounce

        //     if(mlInput::Instance()->event.jaxis.which == 0){
        //         if(mlInput::Instance()->event.jaxis.axis == 0 ){ // X axis motion
        //             if( mlInput::Instance()->event.jaxis.value < -mlInput::Instance()->jDeadZone )
        //             {
        //                 //Left of dead zone
        //                 player->MoveRight();
        //             } else if ( mlInput::Instance()->event.jaxis.value > mlInput::Instance()->jDeadZone ){   
                        
        //                 //Right of deadzone
        //                 player->MoveLeft();
        //             }
        //         }
        //     }
            
        //     break;

        // case SDL_JOYBUTTONDOWN:
        //         PlayerShoot();
        //     break;
        }
    }
}

    

    


void mlStateGame::Update(){

    if(win == true) mpGame->mStateStack.pop_back();

    explosion->Update();

    EnemyUpdate();

    if(mbShoot){
        PlayerShoot();
        mbShoot = false;    
    }

    if(mbLeft) player->MoveLeft();
    if(mbRight) player->MoveRight();

    player->Update();

    ShotsUpdate();

    mpStarfield->Update();

    //sprintf(scoreStr,"SCORE: %i", score);
    snprintf(scoreStr, sizeof(scoreStr), "SCORE: %i", score);
    scoreLabel->SetText(scoreStr);

#ifdef DEBUG
    //sprintf(debugString, "DELTA TIME: %f", mlTime::Instance()->deltaTime);
    snprintf(debugString, sizeof(debugString), "Debug: %f", mlTime::Instance()->deltaTime);
    debug->SetText(debugString);
#endif
}

void mlStateGame::Draw(){
    background->Draw();
    mpStarfield->Draw();
    ShotsDraw();
    EnemyDraw();
    player->Draw();
    explosion->Draw();
    scoreLabel->Draw();
    debug->Draw();
}

/* -------------------------------- Functions ------------------------------- */

void mlStateGame::PlayerShoot(){
    if(!shotsPool.empty()){
        player->isShooting = true;
        shotsShot.push_back(shotsPool.back());
        shotsPool.pop_back();
        shotsShot.back()->yVel = -300;
        shotsShot.back()->dstRect.x = player->dstRect.x + (player->scaledRect.w/2)-1;
        shotsShot.back()->dstRect.y = player->dstRect.y;
        shotsShot.back()->enabled = true;
    }
}

void mlStateGame::ShotsUpdate(){

    if(shotsShot.empty()) return;

    for(int i=0; i<shotsShot.size(); i++){  
        if(shotsShot[i]->enabled){

            shotsShot[i]->dstRect.y += (shotsShot[i]->yVel * mlTime::Instance()->deltaTime);
            shotsShot[i]->dstRect.x += (shotsShot[i]->xVel * mlTime::Instance()->deltaTime);

            if(!enemies.empty()){
                for(int j=0; j<enemies.size(); j++){
                    if(mlUtilities::Instance()->CheckCollisions(shotsShot[i]->scaledRect, enemies[j]->scaledRect)){

                        // Clean up shot
                        shotsShot[i]->enabled = false;
                        shotsShot[i]->yVel = 0;
                        shotsPool.push_back(shotsShot[i]);
                        shotsShot.erase (shotsShot.begin()+i);

                        // Set up explosion
                        explosion->dstRect.x = enemies[j]->dstRect.x - enemies[j]->dstRect.w/2;
                        explosion->dstRect.y = enemies[j]->dstRect.y - enemies[j]->dstRect.h/2;
                        explosion->animCurrentFrame = 0;
                        explosion->enabled = true;

                        // Clean up enemies
                        enemies[j]->enabled = false;
                        enemies.erase(enemies.begin()+j);

                        score += 1;
                    }
                }
            }
        
            if(shotsShot[i]->dstRect.y < 0 - shotsShot[i]->dstRect.h){
                shotsShot[i]->enabled = false;
                shotsShot[i]->yVel = 0;
                shotsPool.push_back(shotsShot[i]);
                shotsShot.erase (shotsShot.begin()+i);
            }
        }  
    }
}

void mlStateGame::ShotsDraw(){
    if(shotsShot.empty()) return;
    
    for(int i=0;i<shotsShot.size();i++){
        shotsShot[i]->Draw();
    }
}

void mlStateGame::EnemyUpdate(){
    if(enemies.empty()){
        win = true;
        return;
    }

    for(int i=0; i<enemies.size(); i++){
        enemies[i]->Update();
    }
}

void mlStateGame::EnemyDraw(){
    if(enemies.empty()) return;

    for(int i=0;i<enemies.size();i++){
        enemies[i]->Draw();
    }
}