#ifndef MLSTARFIELD_H
#define MLSTARFIELD_H

#include "mlCommon.h"
#include "mlEntity.h"

class mlStarField : public mlEntity {
    public:
        mlStarField();
        ~mlStarField();
        
        SDL_Point*  mpPointArray;
        float*      mpSpeedArray;

        void Input();
        void Update();
        void Draw();

        int     mStarQty;   // Amount of stars
        float   mMinVel;
        float   mMaxVel;

    private:
        int i;  // Counter so we don't allocate on the stack
};


#endif