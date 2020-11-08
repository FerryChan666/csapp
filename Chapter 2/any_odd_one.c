#include <stdio.h>
#include <assert.h>

int any_odd_one(unsigned x)
{
    int mask = 0xAAAAAAAA;
//extract all odd numbers of x and use ^ to compare whether all odd numbers are 1
    return !((mask & x) ^ mask);
}
int main(int argc, char *argv[])
{
    assert(any_odd_one(0xAAAAAAAA));
    return 0;
}