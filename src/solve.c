// MIT License
//
// Copyright (c) 2022 Tiernan8r
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
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"
#include "check.h"
#include "solve.h"

int allOpts[16] = {
    0x1,
    0x2,
    0x3,
    0x4,
    0x5,
    0x6,
    0x7,
    0x8,
    0x9,
    0xa,
    0xb,
    0xc,
    0xd,
    0xe,
    0xf,
};

void populateOptions(solve_t *solve_ptr);
void solveEntries(solve_t *solve_ptr);

void solve(board_t *board_ptr)
{
    if (board_ptr == NULL)
    {
        return;
    }

    bool solvable = true;
    solve_t solve = {};
    solve.board_ptr = board_ptr;
    solve_t *solve_ptr = &solve;

    // 1. populate initial options
    // 2. eliminate/solve entries with only 1 option
    //      if none -> exit
    // 3. recalculate options
    // 4. repeat #2->#3 until all solved.
    do
    {
        // Calculate option values on tiles from solved for entries
        populateOptions(solve_ptr);
        // Try solve entries based off of available options
        solveEntries(solve_ptr);

        solvable = solve_ptr->solvable;
    } while (solvable);
}

// Fills out the options arrays in each board entry, based on the solved values in the
// board.
void populateOptions(solve_t *solve_ptr)
{
    bool solvable = false;
    int n = solve_ptr->board_ptr->size;

    // clear all options initially:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                solve_ptr->opts.opts[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int e = solve_ptr->board_ptr->entries[i][j];

            // Any non-zero value is considered solved...
            if (e)
            {
                continue;
            }

            int count = 0;
            // iterate over all values except the entries actual value:
            // can do a bit of logic on 9*9 v 16*16.
            // check row, column, box for val, if not found, add as option.
            for (int k = 0; k < n; k++)
            {
                int opt = allOpts[k];

                bool rowPresent = checkRow(solve_ptr->board_ptr, j, opt);
                bool columnPresent = checkColumn(solve_ptr->board_ptr, i, opt);
                bool boxPresent = checkBox(solve_ptr->board_ptr, i, j, opt);

                if (!rowPresent && !columnPresent && !boxPresent)
                {
                    solve_ptr->opts.opts[i][j][count] = opt;
                    count++;
                }
            }

            // make sure there is atleast one option available, otherwise the
            // board is unsolvable
            if (count < 1)
            {
                continue;
            }

            solvable = true;
        }
    }

    solve_ptr->solvable = solvable;
}

// Finds any entries with only one option and marks the entry as solved.
void solveEntries(solve_t *s_ptr)
{
    if (!s_ptr)
    {
        return;
    }

    board_t *board_ptr = s_ptr->board_ptr;
    if (!board_ptr)
    {
        return;
    }

    bool solvable = false;
    int n = board_ptr->size;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int entry = board_ptr->entries[i][j];
            if (entry)
            {
                continue;
            }

            int numOpts = 0;
            int lastOpt = 0;

            for (int k = 0; k < n; k++)
            {
                int opt = s_ptr->opts.opts[i][j][k];

                if (!opt)
                {
                    continue;
                }
                numOpts++;
                lastOpt = opt;
            }

            if (numOpts == 1)
            {
                board_ptr->entries[i][j] = lastOpt;

                solvable = true;
            }
        }
    }

    s_ptr->solvable = solvable;

    return;
}
