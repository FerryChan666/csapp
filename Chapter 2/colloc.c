#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void *another_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;
    size_t buf_size = nmemb * size;
    //a condition that check the overflow of buf_size
    if (nmemb == buf_size / size)
    {
        void *p = (void *)malloc(buf_size);
        if (p != NULL)
        {
            memset(p, 0, buf_size); //Set the memroy to zero.
        }
        return p;
    }
    return NULL;
}

int main()
{
    void *p;
    p = another_calloc(0x12345, 1);
    assert(p != NULL);
    free(p);

    p = another_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);
    return 0;
}