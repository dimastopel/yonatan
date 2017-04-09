#include "utils.h"

int is_in_the_box(int x, int y, int bx, int by, int bw, int bh)
{
   return 
      x >= bx && x < bx + bw && y >= by && y < by + bh;  
}

/** Robert Jenkins' 96 bit Mix Function. */
uint32_t mix(uint32_t a, uint32_t b, uint32_t c) {
    a -= b; a -= c; a ^= (c>>13);
    b -= c; b -= a; b ^= (a<<8);
    c -= a; c -= b; c ^= (b>>13);
    a -= b; a -= c; a ^= (c>>12);
    b -= c; b -= a; b ^= (a<<16);
    c -= a; c -= b; c ^= (b>>5);
    a -= b; a -= c; a ^= (c>>3);
    b -= c; b -= a; b ^= (a<<10);
    c -= a; c -= b; c ^= (b>>15);
    return c;
}
