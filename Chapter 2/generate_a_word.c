#include<stdio.h>
#include<assert.h>
typedef unsigned char *byte_pointer;
void generate(int x, int y){
    byte_pointer start = (byte_pointer)&x;
    printf("%.2x ", start[0]);

    start = (byte_pointer)&y;
    for(int i = 1; i < sizeof(int); i++){
        printf("%.2x ", start[i]);
    }
}

int main(){
    
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;

    //method 1://But it don't yield a word 0x765432EF
    generate(x, y);

    //method 2:
    size_t mask = 0xff;
    size_t res = (mask & x) | (~mask &y);
    assert(res == 0x765432EF);
}