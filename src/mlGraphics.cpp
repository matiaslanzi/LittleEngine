#include "mlGraphics.h"

// Singleton instance variable
mlGraphics* mlGraphics::gpInstance = nullptr;

// Singleton method
mlGraphics* mlGraphics::Instance(){
    if(gpInstance == nullptr){gpInstance = new mlGraphics();}
    return gpInstance;
}

mlGraphics::mlGraphics(){
    // Initialize SDL
    trace("mlGraphics: Initializing SDL...");

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        trace("mlGraphics: Can't initialize SDL. %s", SDL_GetError());
        exit(-1);
    }

    // Set up logging @TODO: Use logging library or not
    #ifdef DEBUG  
        SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
        trace("mlGraphics: Log set to debug.");
    #else
        SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
        trace("mlGraphics: Log set to info.");
    #endif

    // Set texture filtering 1 nearest pixel, 2 nearest linear, 3 nearest best
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, MLSCALE_QUALITY);
    
    // Create SDL window
    SDL_WindowFlags windowFlags = (SDL_WindowFlags)(SDL_WINDOW_SHOWN /*&& SDL_WINDOW_BORDERLESS*/);
    trace("mlGraphics: Creating window...");
    mpWindow = SDL_CreateWindow((char*)MLWINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            MLWINDOW_WIDTH * MLRENDERSCALEX,
                                            MLWINDOW_HEIGHT * MLRENDERSCALEY,
                                            windowFlags);

    if(mpWindow ==  NULL){
        trace("mlGraphics: Can't create SDL window.\n%s\n", SDL_GetError());
        exit(-1);
    }

    // Create and attach renderer
    trace("mlGraphics: Creating renderer...");
    mpRenderer = SDL_CreateRenderer(mpWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if(mpRenderer == NULL){
        trace("mlGraphics: Can't create SDL renderer\n%s\n", SDL_GetError());
        exit(-1);
    }
    
    // Hide the cursor
    SDL_ShowCursor(SDL_DISABLE);
    trace("mlGraphics: hiding the cursor");

    // TODO: Implement live resizing.
    SDL_RenderSetScale(mpRenderer, MLRENDERSCALEX, MLRENDERSCALEY);

    mDrawColor.r = mDrawColor.g = mDrawColor.b = 0x00;
    mDrawColor.a = 0xff;

    mClearColor = mDrawColor;
    
    SDL_SetRenderDrawColor(mpRenderer, mDrawColor.r, mDrawColor.g, mDrawColor.b, mDrawColor.a);
}

mlGraphics::~mlGraphics(){

    if(mpRenderer){
        SDL_DestroyRenderer(mpRenderer);
        mpRenderer = nullptr;
    }

    if(mpWindow){
        SDL_DestroyWindow(mpWindow);
        mpWindow = nullptr;
    }
    
    trace("mlGraphics: Returning the cursor.");
    SDL_ShowCursor(SDL_ENABLE);

    trace("mlGraphics: Quit SDL");
    SDL_Quit();
}

void mlGraphics::ClearScreen(){
    SDL_SetRenderDrawColor(mpRenderer, mClearColor.r, mClearColor.g, mClearColor.b, mClearColor.a);
    SDL_RenderClear(mpRenderer);
}

void mlGraphics::FlipBuffer(){
    SDL_RenderPresent(mpRenderer);
}