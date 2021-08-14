#ifndef _SOLVE_H
    #define _SOLVE_H

    #include <math.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "entry.h"

    typedef struct {
        int opts[16][16][16];
    } options_t;

    typedef struct {
        board_t *board;
        options_t opts;
        bool solvable;
    } solve_t;

    board_t solve(board_t board);

    solve_t* populateOptions(board_t *board, bool solvable);
    void solveEntries(solve_t *s);

    bool checkRow(board_t *board, int j, int v);
    bool checkColumn(board_t *board, int i, int v);
    bool checkBox(board_t *board, int i, int j, int v);
#endif