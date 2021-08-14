#include "main.h"

grid_t testGrid();

int main() {
    // Read in the input
    printf("READING INPUT:\n");
    grid_t *g_ptr = read(stdin);
    if (!g_ptr) {
        return 1;
    }

    grid_t g = *g_ptr;
    // Calculate options for each entry

    // solve

    // output
    // grid_t g = makeEmptyGrid(9);
    // grid_t g = testGrid();

    printf("INPUT:\n");
    drawTable(g);

    g = solve(g);

    printf("OUTPUT:\n");
    drawTable(g);

    return 0;
}

grid_t testGrid() {
    // make a test 9*9 grid:
    //   0   1   2   3   4   5   6   7   8
    // +---+---+---+---+---+---+---+---+---+
    // | 6 | 4 |   |   | 3 |   |   |   | 7 | 0
    // +---+---+---+---+---+---+---+---+---+
    // | 5 |   | 1 |   | 7 |   | 9 |   |   | 1
    // +---+---+---+---+---+---+---+---+---+
    // |   |   |   |   |   |   |   | 1 |   | 2
    // +---+---+---+---+---+---+---+---+---+
    // |   |   | 4 | 9 |   | 8 |   | 6 |   | 3
    // +---+---+---+---+---+---+---+---+---+
    // |   | 8 |   |   |   | 3 |   | 2 |   | 4
    // +---+---+---+---+---+---+---+---+---+
    // |   |   |   | 4 |   |   |   |   |   | 5
    // +---+---+---+---+---+---+---+---+---+
    // | 4 |   |   | 1 | 5 | 7 |   | 3 |   | 6
    // +---+---+---+---+---+---+---+---+---+
    // | 2 |   | 8 | 3 |   |   |   | 4 |   | 7
    // +---+---+---+---+---+---+---+---+---+
    // | 7 | 5 |   |   |   |   |   | 9 | 6 | 8
    // +---+---+---+---+---+---+---+---+---+
    entry_t e = {
        empty,
        {},
        0,
    };

    grid_t g = {
        {
            // row 0:
            {
                {six, {}, 1,},
                {four, {}, 1,},
                e, e,
                {three, {}, 1,},
                e, e, e,
                {seven, {}, 1,},
            },
            // row 1:
            {
                {five, {}, 1,},
                e,
                {one, {}, 1,},
                e,
                {seven, {}, 1,},
                e,
                {nine, {},1,},
                e,e,
            },
            // row 2:
            {
                e,e,e,e,e,e,
                {one, {}, 1,},
                e,e,
            },
            // row 3
            {
                e,e,
                {four, {}, 1,},
                {nine, {}, 1,},
                e,
                {eight, {}, 1,},
                e,
                {six, {}, 1,},
                e,
            },
            // row 4
            {
                e,
                {eight, {}, 1,},
                e,e,e,
                {three, {}, 1,},
                e,
                {two, {}, 1,},
                e,
            },
            // row 5
            {
                e, e, e,
                {four, {}, 1,},
                e, e, e, e, e,
            },
            // row 6:
            {
                {four, {}, 1,},
                e, e,
                {one, {}, 1,},
                {five, {}, 1,},
                {seven, {}, 1,},
                e,
                {three, {}, 1,},
                e,
            },
            // row 7
            {
                {two, {}, 1,},
                e,
                {eight, {}, 1,},
                {three, {}, 1,},
                e, e, e,
                {four, {}, 1,},
                e,
            },
            // row 8
            {
                {seven, {}, 1,},
                {five, {}, 1,},
                e, e, e, e, e,
                {nine, {}, 1,},
                {six, {}, 1,},
            },
        },
        9,
    };

    return g;
}