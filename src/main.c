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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"
#include "input.h"
#include "output.h"
#include "main.h"
#include "solve.h"

char *program_name;
FILE *input_file = NULL;
board_t *board_ptr = NULL;

void usage(void);

void usage(void)
{
    printf("%s - Solves a given sudoku grid.\n", program_name);
    printf("USAGE:\n\n");
    printf("%s [flags] <file>\n\n", program_name);
    printf("FLAGS:\n\n");
    printf("-h/--help:      Display this message.\n");
    printf("\n");
    printf("VALUES:\n\n");
    printf("<file>:         The file to read for board input, defaults to stdin if unset.\n");

    exit(1);
}

int main(int argc, char *argv[])
{
    input_file = stdin;
    program_name = &argv[0][0];

    char *input_file_name;

    while (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            usage();
        }
        if (argv[1][0] == '-')
        {
            printf("Unrecognised flag '%s'\n", argv[1]);
            usage();
        }
        else
        {
            input_file_name = &argv[1][0];
            input_file = fopen(input_file_name, "r");

            if (input_file == NULL)
            {
                fprintf(stderr, "Unable to open file '%s' for reading\n", input_file_name);
            }
            break;
        }
        --argc;
        ++argv;
    }

    // Read in the input
    printf("READING INPUT...\n");
    board_t board = {};
    board_ptr = &board;
    int status = read(input_file, board_ptr);
    if (status)
    {
        return 1;
    }

    printf("INPUT:\n");
    drawTable(board);

    printf("SOLVING...\n");
    solve(board_ptr);

    printf("OUTPUT:\n");
    drawTable(board);

    return 0;
}
