// Write code for a function with the following prototype:
// /*
// * Mask with least signficant n bits set to 1
// * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
// * Assume 1 <= n <= w
// */
// int lower_one_mask(int n);
// Your function should follow the bit-level integer coding rules (page 164). Be
// careful of the case n = w.

#include<stdio.h>
#include<assert.h>
int lower_one_mask(int n){
    int mask = 1<<31;
    mask = mask >> (n-1);
    mask = (unsigned)mask >> 31 - (n-1);
    return mask;
}

int main(){
    assert(lower_one_mask(6)==0x3F);
    assert(lower_one_mask(17)==0x1FFFF);
    assert(lower_one_mask(32)==-1);
}