#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k)
{

    unsigned xsra = (int)x >> k; /*Perform shift arithmetically*/
    return (~0) ^ xsra;
}

int sra(int x, int k)
{

    int xsrl = (unsigned)x >> k; /*Perform shift logically*/
    return (~0) ^ xsrl;
}

int main()
{
    assert(srl(~0, 32) == 0);
    assert(sra(0, 32) == -1);
    unsigned test_unsigned = 0x12345678;
    int test_int = 0x12345678;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    test_unsigned = 0x87654321;
    test_int = 0x87654321;

    assert(srl(test_unsigned, 4) == test_unsigned >> 4);
    assert(sra(test_int, 4) == test_int >> 4);

    return 0;
}