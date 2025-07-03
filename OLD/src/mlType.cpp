#include "mlType.h"

// Singleton instance variable
mlType* mlType::instance = NULL;

// Singleton method
mlType* mlType::Instance(){
    if(instance == NULL){
        instance = new mlType();
    }
    return instance;
}

mlType::mlType(){

    fontSize = MLFONTSIZE;

    // Initialize fonts 	
    if(TTF_Init()==-1) {
        SDL_Log("mlType: TTF_Init: %s\n", TTF_GetError());
        exit(-1);
    }

    // Open base font
    font = TTF_OpenFont(MLFONTFILE, fontSize);
    if(font == NULL){
        SDL_Log("mlType: Can't load the font file.\n");
        exit(-1);
    }
}

mlType::~mlType(){
}