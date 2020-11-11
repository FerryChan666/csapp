#include <stdio.h>
#include <assert.h>
#include <limits.h>

int tsub_ok(int x, int y){
    int sign_x = x>>31;
    int sign_s = (x-y) >> 31;

    return !sign_x ^ sign_s;
}

int main(){
    assert(!tsub_ok(INT_MIN, 0x1234));
    assert(tsub_ok(0x1234,0x123));
}