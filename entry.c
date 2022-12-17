#include <stdio.h>
#include <strings.h>
#include "entry.h"

const int SMALL_TABLE = 9;
const int BIG_TABLE = 16;

char *charVals = " 123456789ABCDEF0";
int numChars = 17;

char toChar(int e) {
    char val = ' ';

    if (e <= 0 || e > numChars) {
        return val;
    }

    return charVals[e];
}

int fromChar(char c) {
    for (int i = 0; i < numChars; i++) {
        if (charVals[i] == c) {
            return i;
        }
    }

    return 0;
}