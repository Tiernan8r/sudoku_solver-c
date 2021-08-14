#include "grid.h"

grid_t makeEmptyGrid(unsigned int size) {
    grid_t g = {};

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            g.vals[i][j] = makeEmptyEntry();
        }
    }

    g.size = size;

    return g;
}