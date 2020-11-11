#include<stdio.h>
#include<assert.h>
#include<limits.h>

typedef unsigned float_bits;
/*Compute |f|, if f is NaN, then return f.*/
float_bits float_absval(float_bits f){
    printf("%f\n", f);
    int sign = f>>31;
    int exp = f>>23 & 0xff;
    int frac = f & 0x7fffff;
    int is_neg = (f & INT_MIN);
    (is_neg) &&(f=((~sign)<<31) | (exp<<23) | frac);
    return f;
}
int main(){

}
