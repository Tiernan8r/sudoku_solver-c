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
#include <stdio.h>
#include <stdlib.h>
#include "entry.h"
#include "input.h"

extern const int BIG_TABLE;
extern const int SMALL_TABLE;

// Handles reading in the input of the grid:
board_t *parseTable(char *s, int size);

// Reads the entire file input as follows:
// any 0,1,2...9,a...f is read as an entry in the
// grid, any ' ' chars are empty entries, and '\n' are ignored.
board_t *read(FILE *f)
{
    if (!f)
    {
        fclose(f);

        return NULL;
    }

    char c;
    int i = 0;
    char *chars = malloc(BIG_TABLE * BIG_TABLE * sizeof(char));

    while (c != EOF)
    {
        c = fgetc(f);

        if (c == '\n' || c == EOF)
        {
            continue;
        }

        chars[i] = c;
        i++;
    }
    fclose(f);

    int tableWidth = (int)sqrt(i);
    if (tableWidth == SMALL_TABLE || tableWidth == BIG_TABLE)
    {
        return parseTable(chars, i);
    }

    printf("table width did not match expected dimensions!\n");
    free(chars);

    return NULL;
}

// reads the string into the a 2x2 array
board_t *parseTable(char *s, int size)
{
    int w = (int)sqrt(size);

    board_t board = {};
    board_t *b_ptr = &board;

    board.size = w;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c = s[i * w + j];
            board.entries[i][j] = fromChar(c);
        }
    }

    return b_ptr;
}