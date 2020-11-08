#include<stdio.h>
#include<assert.h>

unsigned rotate_left(unsigned x, int n){//n bits
    int mask = 1<<31;
    mask = mask>>(n-1);
    mask = x & mask;

    x = (x<<n) + ((unsigned)mask >> (31 - (n-1)));
    return x;
}

int main(){
    assert(rotate_left(0x12345678, 4)==0x23456781);
}