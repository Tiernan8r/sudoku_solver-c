#include <stdio.h>
#include "entry.h"
#include "solve.h"
#include "input.h"
#include "output.h"
#include "main.h"

board_t* testBoard();

int main() {
    // Read in the input
    printf("READING INPUT:\n");
    board_t *b_ptr = read(stdin);
    if (!b_ptr) {
        return 1;
    }

    board_t b = *b_ptr;
    // Calculate options for each entry

    // solve

    // output
    // board_t b = makeEmptyBoard(9);
    // board_t b = testBoard();
    // b_ptr = testBoard();

    printf("INPUT:\n");
    drawTable(b);

    printf("SOLVING...\n");
    b = solve(b);

    printf("OUTPUT:\n");
    drawTable(b);

    return 0;
}

board_t* testBoard() {
    // make a test 9*9 board:
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
    board_t b = {
        {
            // row 0:
            {
                6,4,0,0,3,0,0,0,7,
            },
            // row 1:
            {
                5,0,1,0,7,0,9,0,0,
            },
            // row 2:
            {
                0,0,0,0,0,0,0,1,0,
            },
            // row 3
            {
                0,0,4,9,0,8,0,6,0,
            },
            // row 4
            {
                0,8,0,0,0,3,0,2,0,
            },
            // row 5
            {
                0,0,0,4,0,0,0,0,0,
            },
            // row 6:
            {
                4,0,0,1,5,7,0,3,0,
            },
            // row 7
            {
                2,0,8,3,0,0,0,4,0,
            },
            // row 8
            {
                7,5,0,0,0,0,0,9,6,
            },
        },
        9,
    };

    board_t *b_ptr = &b;
    return b_ptr;

    // return b;
}