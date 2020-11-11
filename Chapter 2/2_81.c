#include<stdio.h>
#include<assert.h>

int A(int k){
    int x = -1;
    return x<<k;
}

int B(int k, int j){
    int x=-1;
    return ~(x<<k) << j;
}

int main(){
    assert(A(16)==0xffff0000);
    assert(B(8, 8)==0x0000ff00);
}