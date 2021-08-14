#ifndef _ENTRY_H
    #define _ENTRY_H
    
    #include <stdio.h>
    #include "value.h"

    typedef struct {
        value_t val;
        value_t options[16];
        unsigned int solved:1;
    } entry_t;

    char toChar(entry_t e);
    entry_t fromChar(char c, int solved);

    entry_t makeEmptyEntry();

#endif