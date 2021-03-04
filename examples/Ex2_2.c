#include <stdio.h>
int main()
{
    int x = 10;
    int k = 11;
    int y = (x|1<<k) & ~(1<<k/2);
    printf("%d -> %d \n", x, y);
}
