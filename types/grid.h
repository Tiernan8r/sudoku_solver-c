#ifndef _GRID_H
    #define _GRID_H

    #include <stdio.h>
    #include "entry.h"

    typedef struct {
        entry_t vals[16][16];
        unsigned int size:4;
    } grid_t;

    grid_t makeEmptyGrid(unsigned int size);
#endif