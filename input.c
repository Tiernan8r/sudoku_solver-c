// Handles reading in the input of the grid:
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "entry.h"
#include "input.h"

extern const int BIG_TABLE;
extern const int SMALL_TABLE;

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