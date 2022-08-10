#ifndef MLUTILITIES_H
#define MLUTILITIES_H

#include "mlCommon.h"

class mlUtilities{
public:
    static mlUtilities* Instance();
    ~mlUtilities();

    bool CheckCollisions(SDL_Rect& a, SDL_Rect& b);
    int MapRange(int oldMin, int oldMax, int newMin, int newMax, int value);
    int MapRange(float oldMin, float oldMax, float newMin, float newMax, float value);

private:
    static mlUtilities   *instance;

    mlUtilities();                               // Can not be called
    mlUtilities(const mlUtilities& orig){};           // copy constructor is private
};

#endif