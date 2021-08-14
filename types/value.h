#ifndef _VALUE_H
    #define _VALUE_H

    typedef enum {
        empty = 0,
        zero = 1,
        one = 2,
        two = 3,
        three = 4,
        four = 5,
        five = 6,
        six = 7,
        seven = 8,
        eight = 9,
        nine = 10,
        a = 11,
        b = 12,
        c = 13,
        d = 14,
        e = 15,
        f = 16,
    } value_t;

    char getChar(value_t v);
    value_t getVal(char c);
#endif