#ifndef MLINPUT_H
#define MLINPUT_H

#include "mlCommon.h"

class mlInput{
public:
    static mlInput* Instance();
    ~mlInput();

    SDL_Event       event;
    bool            newEvent;

    SDL_Joystick    *gameController;
    Uint32          jDeadZone;

    bool GetInput();

 private:
    static mlInput  *instance;

    mlInput();
    mlInput(const mlInput& orig){};
};

#endif /* MLINPUT_H */