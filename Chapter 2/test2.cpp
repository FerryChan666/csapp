#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for(i=0; i<len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main()
{
    int x =53191;
    short sx = (short)x;

    printf("%d\n", sx);

    int y=sx;
    printf("%d\n", y);
    show_bytes((byte_pointer)&x, sizeof(int));
    show_bytes((byte_pointer)&sx, sizeof(short));
    show_bytes((byte_pointer)&y, sizeof(int));
}