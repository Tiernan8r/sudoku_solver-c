#ifndef _ENTRY_H
    #define _ENTRY_H
    
    #include <stdio.h>
    #include <strings.h>

    typedef struct {
        int entries[16][16];
        unsigned int size:4;
    } board_t;

    char toChar(int e);
    int fromChar(char c);
#endif