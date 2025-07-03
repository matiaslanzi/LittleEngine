#ifndef MLGRAPHICS_H
#define MLGRAPHICS_H

#include "mlCommon.h"

class mlGraphics{
public:
    static mlGraphics* Instance();
    ~mlGraphics();

    void FlipBuffer();
    void ClearScreen();

    SDL_Color           mDrawColor;
    SDL_Color           mClearColor;

    SDL_Window*         mpWindow;
    SDL_Renderer*       mpRenderer;
    

private:
    static mlGraphics*  gpInstance;

    mlGraphics();                                   // Can not be called
    mlGraphics(const mlGraphics& orig){};           // copy constructor is private
};

#endif /* MLGRAPHICS_H */