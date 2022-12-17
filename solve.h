// MIT License
//
// Copyright (c) 2020 Tiernan8r
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#ifndef SOLVE_H
    #define SOLVE_H

    #include <stdbool.h>
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