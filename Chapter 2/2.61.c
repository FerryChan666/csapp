#include <stdio.h>
#include <assert.h>
int A(int x)
{ //any_bit_1
    return !~x;
}

int B(int x)
{ //any_bit_0
    return !x;
}

int C(int x)
{
    //any_least_significant_byte_1 
    return !((0xff & x)^0xff);
}

int D(int x)
{
    //any_most_significant_byte_0 
    return !((0xff << (3 << 3)) & x);
}

int main()
{
    int all_bit_one = ~0;
    int all_bit_zero = 0;
    assert(A(all_bit_one));
    assert(!B(all_bit_one));
    assert(C(all_bit_one));
    assert(!D(all_bit_one));

    assert(!A(all_bit_zero));
    assert(B(all_bit_zero));
    assert(!C(all_bit_zero));
    assert(D(all_bit_zero));

    // test magic number 0x1234ff
    assert(!A(0x1234ff));
    assert(!B(0x1234ff));
    assert(C(0x1234ff));
    assert(D(0x1234ff));

    // test magic number 0x1234
    assert(!A(0x1234));
    assert(!B(0x1234));
    assert(!C(0x1234));
    assert(D(0x1234));

    return 0;
}