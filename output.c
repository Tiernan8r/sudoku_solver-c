// Displays the board as a table
#include <stdio.h>
#include <string.h>
#include "entry.h"
#include "output.h"

char *joint = "+";
char rowSeparator[] = "---";
char *column = "|";

void drawTable(board_t board)
{
    // calculate the amount of memory resuired for the string table:
    // For each row there is an '\n' key, so each is +2 in width.
    // Each entry is 3 chars wide
    // with n+1 columns as dividers.
    // There are n+1 dividers.
    // n = board.size in this case.
    // So there are 2n+1 rows, each of with (3n + (n+1) + 2) = 4n+3
    // total memory required = (2n+1)*(4n+3) = 8n^2+6n+4n+3 = 8n**2 + 10n + 3
    int n = board.size;
    int memorySize = 8 * n * n + 10 * n + 3;

    char table[memorySize];
    memset(table, 0, memorySize * sizeof(char));
    table[0];

    // Construct the row separator:
    int rowSize = 4 * n + 3;
    char row[rowSize];
    memset(row, 0, rowSize * sizeof(char));
    row[0];

    for (int i = 0; i < n; i++)
    {
        strcat(row, joint);
        strcat(row, rowSeparator);
    }
    strcat(row, joint);
    strcat(row, "\n");

    // Populate the table string:
    for (int i = 0; i < n; i++)
    {
        strcat(table, row);
        for (int j = 0; j < n; j++)
        {
            strcat(table, column);
            strcat(table, " ");

            // Write the Actual entry value to the table.
            char e[1];
            e[0] = toChar(board.entries[i][j]);
            strcat(table, e);
            strcat(table, " ");
        }
        strcat(table, column);
        strcat(table, "\n");
    }
    // Add the final bottom row separator
    strcat(table, row);

    printf(table);
}