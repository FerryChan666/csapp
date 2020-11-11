#include<stdio.h>
#include<assert.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f){
    unsigned sign = f>>31;
    unsigned exp = f>>23 & 0xff;
    unsigned frac = f & 0x7fffff;//frac is not f
    int is_NAN = (exp == 0xff && frac != 0);
    if(is_NAN){
        return f;
    }
    else
        return ~sign<<31 | exp<<23 | frac;
}

int main(){
    printf("%f",float_negate(8));
}