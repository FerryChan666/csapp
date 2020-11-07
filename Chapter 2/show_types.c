#include<stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for(i=0; i < len; i++){
        printf("%.2x ", *(start + i));
    }
    printf("\n");
}

void show_long(long x){
    show_bytes((byte_pointer)&x, sizeof(long));
}
int main(){
    long l = 14;
    show_long(l);
}