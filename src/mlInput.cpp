#include "mlInput.h"

// Singleton instance variable
mlInput* mlInput::instance = NULL;

// Singleton method
mlInput* mlInput::Instance(){
    if(instance == NULL){
        instance = new mlInput();
    }
    return instance;
}

mlInput::mlInput(){
     trace( "mlInput: Initializing\n" );

    jDeadZone = 18000;
    //jDeadZone = 10000;
    
    // Initialize joysticks
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS,"1");

    // Check for joysticks
    if( SDL_NumJoysticks() < 1 ){
        trace( "mlInput: No joysticks connected!\n" );
    } else {    
    
        trace( "mlInput: Joysitck found...\n" );

        // Load joystick
        gameController = SDL_JoystickOpen( 0 );
        if( gameController == NULL ){
            trace( "mlInput: Unable to open game controller! SDL Error: %s\n", 
            SDL_GetError() );

            if(instance){
                delete instance;
            }
        }
    }
}

mlInput::~mlInput(){
    if(gameController){
        SDL_JoystickClose( gameController );
        gameController = NULL; 
        instance = NULL;
    }
}

bool mlInput::GetInput(){
    return SDL_PollEvent(&event);
}
