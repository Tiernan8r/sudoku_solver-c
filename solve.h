#ifndef _SOLVE_H
    #define _SOLVE_H

    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "types/value.h"
    #include "types/entry.h"
    #include "types/grid.h"

    grid_t solve(grid_t grid);

    int populateOptions(grid_t *grid);
    int solveEntries(grid_t *grid);

    int checkRow(grid_t *grid, int j, value_t v);
    int checkColumn(grid_t *grid, int i, value_t v);
    int checkBox(grid_t *grid, int i, int j, value_t v);
#endif