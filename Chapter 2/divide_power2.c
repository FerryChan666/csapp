#include<stdio.h>
#include<assert.h>
#include<limits.h>


//x/2^k
int divide_power2(int x, int k){
    int is_neg = INT_MIN & x;
    int bias = (1<<k)-1;
    //if is_neg is false, (x = x + (1 << k) - 1) would not be execute
    is_neg && (x = x + bias);
    return x>>k;
}

int main(){
    assert(divide_power2(9,2)==9/4);
    assert(divide_power2(-0x12345,4)==-0x12345/16);

}