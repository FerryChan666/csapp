#include <stdio.h>
#include <assert.h>
#include<limits.h>

int divide_power2(int x, int k){
    int is_neg = INT_MIN & x;
    int bias = (1<<k)-1;
    //if is_neg is false, (x = x + (1 << k) - 1) would not be execute
    is_neg && (x = x + bias);
    return x>>k;
}

int mul3div4(int x)
{
    return divide_power2((x + (x << 1)), 2);
}

int main()
{
    int x = 0x3;
    assert(mul3div4(x) == 3 * x / 4);
    assert(mul3div4(-x) == 3 * -x / 4);
    int y = 0x87654321;
    assert(mul3div4(y) == y * 3 / 4);
    return 0;
}