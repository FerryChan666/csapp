#include <stdio.h>
#include <assert.h>

int odd_ones(unsigned x)
{
    return !!(0xAAAAAAAA & x);
}

int main()
{
    assert(odd_ones(0b10101011));
    assert(!odd_ones(0b01010101));
    return 0;
}