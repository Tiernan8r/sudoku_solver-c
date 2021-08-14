// Defines the values of the sudoku gird, and how to display them.
#include "value.h"
#include <stdio.h>

char getChar(value_t v) {
    char val = ' ';

    switch (v) {
        case zero:
            val = '0';
            break;
        case one:
            val = '1';
            break;
        case two:
            val = '2';
            break;
        case three:
            val = '3';
            break;
        case four:
            val = '4';
            break;
        case five:
            val = '5';
            break;
        case six:
            val = '6';
            break;
        case seven:
            val = '7';
            break;
        case eight:
            val = '8';
            break;
        case nine:
            val = '9';
            break;
        case a:
            val = 'A';
            break;
        case b:
            val = 'B';
            break;
        case c:
            val = 'C';
            break;
        case d:
            val = 'D';
            break;
        case e:
            val = 'E';
            break;
        case f:
            val = 'F';
            break;
        default:
            break;
    }

    return val;
}

value_t getVal(char c) {
    value_t val = empty;

    switch (c) {
        case '0':
            val = zero;
            break;
        case '1':
            val = one;
            break;
        case '2':
            val = two;
            break;
        case '3':
            val = three;
            break;
        case '4':
            val = four;
            break;
        case '5':
            val = five;
            break;
        case '6':
            val = six;
            break;
        case '7':
            val = seven;
            break;
        case '8':
            val = eight;
            break;
        case '9':
            val = nine;
            break;
        case 'a':
            val = a;
            break;
        case 'A':
            val = a;
            break;
        case 'b':
            val = b;
            break;
        case 'B':
            val = b;
            break;
        case 'c':
            val = c;
            break;
        case 'C':
            val = c;
            break;
        case 'd':
            val = d;
            break;
        case 'D':
            val = d;
            break;
        case 'e':
            val = e;
            break;
        case 'E':
            val = e;
            break;
        case 'f':
            val = f;
            break;
        case 'F':
            val = f;
            break;
        default:
            break;
    }

    return val;
}