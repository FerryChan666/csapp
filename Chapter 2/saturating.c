#include <stdio.h>
#include <assert.h>
#include <limits.h>
/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y)
{

    //firstly, according to propertie of 2's complement
    int sign = 1 << 31;
    int sign_x = x >> 31;
    int sign_s = (x + y) >> 31;

    //if sign_s overflow, condition = 0x8000(Tmin), 
    int condition = (sign_s ^ sign_x) << 31;

    return condition ^ sign_s; //we can find that it is successful.
}

int main()
{
    assert(saturating_add(0xff000000, 0x80000000) == 0x80000000); //TMin
    assert(saturating_add(0x7fffffff, 0xf) == 0x7fffffff);        //TMax

    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
}