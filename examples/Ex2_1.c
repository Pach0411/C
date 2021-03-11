#include <stdio.h>
#include <math.h>
#define BASE 9
int main()
{
    int a = 9100 ;
    int d = log(a)/log(BASE)+1 ;
    printf("%d needs %d digits in base %d\n\n", a, d, BASE);

    return 0;

}

   


