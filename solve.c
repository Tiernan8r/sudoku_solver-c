#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"
#include "solve.h"

extern const int BIG_TABLE;
extern const int SMALL_TABLE;

const int T = true;
const int F = false;

board_t solve(board_t board)
{
    // 1. populate intial options
    // 2. eliminate/solve entries with only 1 option
    //      if none -> exit
    // 3. recalculate options
    // 4. repeat #2->#3 until all solved.
    bool solvable = true;

    do
    {
        solve_t *s_ptr = populateOptions(&board, solvable);

        solveEntries(s_ptr);

        solvable = s_ptr->solvable;
    } while (solvable);

    return board;
}

// Fills out the options arrays in each board entry, based on the solved values in the
// board.
solve_t *populateOptions(board_t *board, bool solvable)
{
    solvable = false;
    if (!board)
    {
        return NULL;
    }

    int n = board->size;
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
        0xf1,
    };

    solve_t solver = {};
    solve_t *s_ptr = &solver;

    // clear all options initially:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                solver.opts.opts[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int e = board->entries[i][j];

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

                bool rowPresent = checkRow(board, j, opt);
                bool columnPresent = checkColumn(board, i, opt);
                bool boxPresent = checkBox(board, i, j, opt);

                if (!rowPresent && !columnPresent && !boxPresent)
                {
                    solver.opts.opts[i][j][count] = opt;
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

    solver.board = board;
    solver.solvable = solvable;

    return s_ptr;
}

// Finds any entries with only one option and marks the entry as solved.
void solveEntries(solve_t *s)
{
    if (!s)
    {
        return;
    }

    board_t *board = s->board;
    if (!board)
    {
        return;
    }

    bool solvable = false;
    int n = board->size;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int entry = board->entries[i][j];
            if (entry)
            {
                continue;
            }

            int numOpts = 0;
            int lastOpt = 0;

            for (int k = 0; k < n; k++)
            {
                int opt = s->opts.opts[i][j][k];

                if (!opt)
                {
                    continue;
                }
                numOpts++;
                lastOpt = opt;
            }

            if (numOpts == 1)
            {
                board->entries[i][j] = lastOpt;

                solvable = true;
            }
        }
    }

    s->solvable = solvable;

    return;
}

// Checks the rows of the given index to see if value 'v' is present in
// any, returns true if value is present.
bool checkRow(board_t *board, int j, int v)
{
    if (!board)
    {
        return false;
    }

    for (int i = 0; i < board->size; i++)
    {
        int entry = board->entries[i][j];

        if (entry && entry == v)
        {
            return true;
        }
    }

    return false;
}

// Checks the columns of the given index to see if value 'v' is present in
// any, returns true if value is present.
bool checkColumn(board_t *board, int i, int v)
{
    if (!board)
    {
        return false;
    }

    for (int j = 0; j < board->size; j++)
    {
        int entry = board->entries[i][j];

        if (entry && entry == v)
        {
            return true;
        }
    }

    return false;
}

// Checks the n*n box the entry lives in for value 'v' if present, returns true if so.
bool checkBox(board_t *board, int i, int j, int v)
{
    if (!board)
    {
        return false;
    }

    int n = (int)sqrt(board->size);

    int minX = floor(i / n) * n;
    int minY = floor(j / n) * n;

    for (int x = minX; x < minX + n; x++)
    {
        for (int y = minY; y < minY + n; y++)
        {
            int entry = board->entries[x][y];

            if (entry && entry == v)
            {
                return true;
            }
        }
    }

    return false;
}