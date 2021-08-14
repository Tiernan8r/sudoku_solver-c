#include "entry.h"

char toChar(entry_t e) {
    if (!e.solved) {
        return ' ';
    }

    return getChar(e.val);
}

entry_t fromChar(char c, int solved) {
    value_t val = getVal(c);

    entry_t e = makeEmptyEntry();
    e.val = val;
    e.solved = solved;

    return e;
}

entry_t makeEmptyEntry() {
    entry_t emptyEntry = {
        empty,
        {},
        0,
    };

    return emptyEntry;
}
