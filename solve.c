// Displays the grid as a table
#include "solve.h"

int populateOptions(grid_t *grid);
int solveEntries(grid_t *grid);

int checkRow(grid_t *grid, int j, value_t v);
int checkColumn(grid_t *grid, int i, value_t v);
int checkBox(grid_t *grid, int i, int j, value_t v);

grid_t solve(grid_t grid) {
    // 1. populate intial options
    // 2. eliminate/solve entries with only 1 option
    //      if none -> exit
    // 3. recalculate options
    // 4. repeat #2->#3 until all solved.

    int populateSolvable = 1;
    int eliminateSolvable = 1;

    int count = 0;
    do {
        count++;

        populateSolvable = populateOptions(&grid);
        eliminateSolvable = solveEntries(&grid);
    } while (populateSolvable && eliminateSolvable);

    return grid;
}

// Fills out the options arrays in each grid entry, based on the solved values in the
// grid.
int populateOptions(grid_t *grid) {
    int solvable = 0;

    value_t allOpts[16] = {
        one, two, three, four, five, six, seven, eight, nine, a, b, c, d, e, f, zero,
    };

    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            entry_t e = grid->vals[i][j];

            if (e.solved) {
                continue;
            }

            value_t *opts = malloc(grid->size * sizeof(value_t));
            for (int i = 0; i < grid->size; i++) {
                opts[i] = empty;
            }

            int count = 0;
            // iterate over all values except the entries actual value:
            // can do a bit of logic on 9*9 v 16*16.
            // check row, column, box for val, if not found, add as option. 
            for (int k = 0; k < grid->size; k++) {
                value_t opt = allOpts[k];

                int rowPresent = checkRow(grid, j, opt);
                int columnPresent = checkColumn(grid, i, opt);
                int boxPresent = checkBox(grid, i, j, opt);

                if (!(rowPresent || columnPresent || boxPresent)) {
                    opts[count] = opt;
                    count++;
                }
            }

            // make sure there is atleast one option available, otherwise the
            // grid is unsolvable
            if (count < 1) {
                continue;
            }

            entry_t *newEntry = malloc(sizeof(entry_t));
            newEntry->solved=0;
            newEntry->val = grid->vals[i][j].val;
    
            for (int x = 0; x < count; x++) {
                newEntry->options[x] = opts[x];
            }

            grid->vals[i][j] = *newEntry;
            solvable = 1;
        }
    }

    return solvable;
}

// Finds any entries with only one option and marks the entry as solved.
int solveEntries(grid_t *grid) {
    int solvable = 0;

    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            entry_t entry = grid->vals[i][j];
            if (entry.solved) {
                continue;
            }

            int totalOptions = sizeof(entry.options) / sizeof(entry.options[0]);

            int numOptions = 0;
            value_t lastOption = empty;

            for (int k = 0; k < totalOptions; k++) {
                value_t opt = entry.options[k];
                if (opt == empty) {
                    continue;
                }

                numOptions++;
                lastOption = opt;
            }

            if (numOptions == 1) {
                entry_t newEntry = {
                    lastOption,
                    {},
                    1,
                };

                grid->vals[i][j] = newEntry;

                solvable = 1;
            }
        }
    }

    return solvable;
}

// Checks the rows of the given index to see if value 'v' is present in
// any, returns 1 if so.
int checkRow(grid_t *grid, int j, value_t v) {
    if (grid == NULL) {
        return 0;
    }

    for (int i = 0; i < grid->size; i++) {
        entry_t entry = grid->vals[i][j];

        if (entry.solved) {
            if (entry.val == v) {
                return 1;
            }
        }
    }

    return 0;
}

// Checks the columns of the given index to see if value 'v' is present in
// any, returns 1 if so.
int checkColumn(grid_t *grid, int i, value_t v) {
    if (grid == NULL) {
        return 0;
    }

    for (int j = 0; j < grid->size; j++) {
        entry_t entry = grid->vals[i][j];

        if (entry.solved) {
            if (entry.val == v) {
                return 1;
            }
        }
    }

    return 0;
}

// Checks the n*n box the entry lives in for value 'v' if present, returns 1 if so.
int checkBox(grid_t *grid, int i, int j, value_t v) {
    if (grid == NULL) {
        return 0;
    }

    int n = (int) sqrt(grid->size);

    int minX = floor(i / n) * n;
    int minY = floor(j / n) * n;

    for (int x = minX; x < minX + n; x++) {
        for (int y = minY; y < minY + n; y++) {
            entry_t entry = grid->vals[x][y];

            if (entry.solved) {
                if (entry.val == v) {
                    return 1;
                }    
            }
        }
    }

    return 0;
}