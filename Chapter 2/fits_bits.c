#include<stdio.h>
#include<assert.h>
/*
* Return 1 when x can be represented as an n-bit, 2’s-complement
* number; 0 otherwise
* Assume 1 <= n <= w
*/

int fit_bits(int x, int n){
    int w = sizeof(int) << 3;
    return x==(x<<(w-n)>>(w-n));
}

int main(){
    assert(fit_bits(0b010, 3));
    assert(!fit_bits(0b010, 2));
    assert(fit_bits(-1, 32));
}