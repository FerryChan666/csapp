#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k)/*Perform a logical right shift*/
{
    unsigned xsra = (int)x >> k; /*Perform shift arithmetically*/

    int w = sizeof(int)<<3;
    int mask = (int)(-1) << (w - k);
    return ~mask & xsra;
}

int sra(int x, int k)   /*Perform a arithmetic right shift*/
{

    int xsrl = (unsigned)x >> k; /*Perform shift logically*/

    int w = sizeof(int)<<3;
    int mask = (int)-1 << (w - k);
    
    int m = 1 << (w - 1);
    mask &= !(x & m) - 1;   
    return mask | xsrl;
}

int main()
{
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