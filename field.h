#ifndef FIELD_H
#define FIELD_H

#include "enums.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

class field
{
public:

    int fieldLength;
    int fieldWidth;

    cell **_field;

    //std::vector < std::vector<cell> > _field;

    field();

    field (const field &o);

    void spawnFood();

    ~field();

};

#endif // FIELD_H
