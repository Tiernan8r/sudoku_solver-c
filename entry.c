#include "entry.h"

const int SMALL_TABLE = 9;
const int BIG_TABLE = 16;

char toChar(int e) {
    char val = ' ';

    switch (e) {
        // case 0:
        //     val = '0';
        //     break;
        case 1:
            val = '1';
            break;
        case 2:
            val = '2';
            break;
        case 3:
            val = '3';
            break;
        case 4:
            val = '4';
            break;
        case 5:
            val = '5';
            break;
        case 6:
            val = '6';
            break;
        case 7:
            val = '7';
            break;
        case 8:
            val = '8';
            break;
        case 9:
            val = '9';
            break;
        case 0xa:
            val = 'A';
            break;
        case 0xb:
            val = 'B';
            break;
        case 0xc:
            val = 'C';
            break;
        case 0xd:
            val = 'D';
            break;
        case 0xe:
            val = 'E';
            break;
        case 0xf:
            val = 'F';
            break;
        case 0xf1:
            val = '0';
            break;
        default:
            break;
    }

    return val;
}

int fromChar(char c) {
    int val = 0;

    switch (c) {
        case '0':
            val = 17;
            break;
        case '1':
            val = 1;
            break;
        case '2':
            val = 2;
            break;
        case '3':
            val = 3;
            break;
        case '4':
            val = 4;
            break;
        case '5':
            val = 5;
            break;
        case '6':
            val = 6;
            break;
        case '7':
            val = 7;
            break;
        case '8':
            val = 8;
            break;
        case '9':
            val = 9;
            break;
        case 'a':
            val = 0xa;
            break;
        case 'A':
            val = 0xa;
            break;
        case 'b':
            val = 0xb;
            break;
        case 'B':
            val = 0xb;
            break;
        case 'c':
            val = 0xc;
            break;
        case 'C':
            val = 0xc;
            break;
        case 'd':
            val = 0xd;
            break;
        case 'D':
            val = 0xd;
            break;
        case 'e':
            val = 0xe;
            break;
        case 'E':
            val = 0xe;
            break;
        case 'f':
            val = 0xf;
            break;
        case 'F':
            val = 0xf;
            break;
        default:
            break;
    }

    return val;
}