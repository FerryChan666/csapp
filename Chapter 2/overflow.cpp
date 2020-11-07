#include <iostream>
using namespace std;
int uadd_ok(unsigned x, unsigned y);

int tadd_ok(int x, int y);

int tsub_ok(int x, int y);

int main()
{
    if(tsub_ok(4, 4))
        printf("ok");
}

int uadd_ok(unsigned x, unsigned y)
{
    if (x + y >= x)
        return 1;
    else
        return 0;
}

int tadd_ok(int x, int y)
{
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x>=0 && y>=0 &&sum<0;
    return !neg_over && !pos_over;
}

int tsub_ok(int x, int y){
    return tadd_ok(x, y)&& tadd_ok(x,-y) || !tadd_ok(x, y) && tadd_ok(x, -y);
}
