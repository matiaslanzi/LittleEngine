#ifndef MLTYPE_H
#define MLTYPE_H

/*
 * TODO: @matiaslanzi This class should be called text.
 */

#include "mlCommon.h"

class mlType{
public:
    static mlType* Instance();
    ~mlType();

    TTF_Font    *font;
    Uint16      fontSize;

private:
    static mlType   *instance;

    mlType();                               // Can not be called
    mlType(const mlType& orig){};           // copy constructor is private
};

#endif /* MLTYPE_H */