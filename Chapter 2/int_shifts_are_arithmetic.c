#include<stdio.h>
#include<assert.h>

int int_shifts_are_arithmetic(){
    int a=~0xff;
    int b=0xff;
    return !~(a>>((sizeof(int)-1) << 3)) & !(b>>((sizeof(int) -1)<<3));
}

int main(){
    assert(int_shifts_are_arithmetic());
}