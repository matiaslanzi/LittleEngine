#include "mlUtilities.h"

// Singleton instance variable
mlUtilities* mlUtilities::instance = NULL;

// Singleton method
mlUtilities* mlUtilities::Instance(){
    if(instance == NULL){
        instance = new mlUtilities();
    }
    return instance;
}

mlUtilities::mlUtilities(){

}

mlUtilities::~mlUtilities(){
    
}

bool mlUtilities::CheckCollisions(SDL_Rect& a, SDL_Rect& b){

    if(((a.x + a.w) >= b.x && a.x <= (b.x + b.w)) && ((a.y + a.h) >= b.y && a.y <= (b.y + b.h)))
        return true;

    return false;
}

int mlUtilities::MapRange (int oldMin, int oldMax, int newMin, int newMax, int value){
	int oldRange = (oldMax - oldMin);
	int newRange = (newMax - newMin);
	return (((value - oldMin) * newRange) / oldRange) + newMin;
}