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
#include <math.h>
#include <stdbool.h>
#include "entry.h"
#include "check.h"

// Checks the rows of the given index to see if value 'v' is present in
// any, returns true if value is present.
bool checkRow(board_t *board_ptr, int j, int v)
{
    if (!board_ptr)
    {
        return false;
    }

    for (int i = 0; i < board_ptr->size; i++)
    {
        int entry = board_ptr->entries[i][j];

        if (entry && entry == v)
        {
            return true;
        }
    }

    return false;
}

// Checks the columns of the given index to see if value 'v' is present in
// any, returns true if value is present.
bool checkColumn(board_t *board_ptr, int i, int v)
{
    if (!board_ptr)
    {
        return false;
    }

    for (int j = 0; j < board_ptr->size; j++)
    {
        int entry = board_ptr->entries[i][j];

        if (entry && entry == v)
        {
            return true;
        }
    }

    return false;
}

// Checks the n*n box the entry lives in for value 'v' if present, returns true if so.
bool checkBox(board_t *board_ptr, int i, int j, int v)
{
    if (!board_ptr)
    {
        return false;
    }

    int n = (int)sqrt(board_ptr->size);

    int minX = floor(i / n) * n;
    int minY = floor(j / n) * n;

    for (int x = minX; x < minX + n; x++)
    {
        for (int y = minY; y < minY + n; y++)
        {
            int entry = board_ptr->entries[x][y];

            if (entry && entry == v)
            {
                return true;
            }
        }
    }

    return false;
}