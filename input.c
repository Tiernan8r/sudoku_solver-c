// Handles reading in the input of the grid:

#include "input.h"

const int SMALL_TABLE = 9;
const int BIG_TABLE = 16;

grid_t* parseTable(char *s, int size);

// Reads the entire file input as follows:
// any 0,1,2...9,a...f is read as an entry in the
// grid, any ' ' chars are empty entries, and '\n' are ignored.
grid_t* read(FILE *f) {

    if (!f) {
        fclose(f);

        return NULL;
    }

    char c;
    int i = 0;
    char *entries = malloc(BIG_TABLE * BIG_TABLE * sizeof(char));

    while (c != EOF) {
        c = fgetc(f);

        if (c == '\n' || c == EOF) {
            continue;
        }

        entries[i] = c;
        i++;
    }
    fclose(f);

    int tableWidth = (int) sqrt(i);
    if (tableWidth == SMALL_TABLE || tableWidth == BIG_TABLE) {
        return parseTable(entries, i);
    }
    
    printf("table width did not match expected dimensions!\n");
    free(entries);

    return NULL;
}

// reads the string into the a grid table
grid_t* parseTable(char *s, int size) {
    grid_t g = {};
    grid_t *g_ptr;

    int w = (int) sqrt(size);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            char c = s[i * w + j];

            int solved = (c != getChar(empty));
            
            entry_t e = fromChar(c, solved);

            g.vals[i][j] = e;
        }
    }
    g.size = w;

    g_ptr = &g;
    return g_ptr;
}