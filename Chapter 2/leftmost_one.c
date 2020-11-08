#include<stdio.h>
#include<assert.h>

int leftmost_one(unsigned x){
    //Reconstruct x , its bits after leftmost are all one.
    x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    //shifting right and plusing 1 just eliminate all ones after leftmost. 
    return (x >> 1) + (x && 1);
}

int main(){
    assert(leftmost_one(0xFF00)==0x8000);
}