#include<stdio.h>
#include<assert.h>
typedef unsigned char *byte_pointer;

unsigned replace_byte(unsigned x, int i, unsigned char b){
    if(i < 0){
    printf("error: i is negative");
    return x;
    }
    if (i > sizeof(unsigned)-1)
    {
        printf("error: too big i");
        return x;
    }

    byte_pointer start_x = (byte_pointer)&x;
    start_x[i]=b;
    return x;
}

unsigned replace_byte_2(unsigned x, int i, unsigned char b){
    if(i < 0){
        printf("error: i is negative");
        return x;
    }
    if (i > sizeof(unsigned)-1)
    {
        printf("error: too big i");
        return x;
    }
    
    unsigned mask = 0xff << (i << 3);   // i << 3 equals to i * 2^3 equaling to i * 1 byte
    unsigned pos_byte = b << (i << 3);
    return  pos_byte | (x & ~mask);
}

int main(){
    //method 1:
    unsigned rep_0 =  replace_byte(0x12345678, 2, 0xAB);
    assert(rep_0 == 0x12AB5678);
    assert(replace_byte(0x12345678, 0, 0XAB) == 0x123456AB);
    //method 2:
    assert(replace_byte_2(0x12345678, 3, 0XAB) == 0xAB345678);
}