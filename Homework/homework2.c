#include <stdio.h>
#include <math.h>
#define K  18
void prime(int y);
void binary(int p);
int main(){
    prime(K);
    return 0;
}


void binary(int p)
{
    int i=0;
    int base[6]={0};
    while (p>0)
    {
        base[i]= p%2;
        p/=2;
        ++i;
    }
    
        for(int x=5;x>=0;--x)
    {
        printf("%01d", base[x]);
    }
    printf("\n");
}
void prime(int k) 
{
    int count, i, flag, sr;
    int n=1;
    count = 1;

    while(count <= k)
    {
        sr=sqrt(n);
        flag=0;
        for(i=2; i<= sr; i++){
            if(n%i==0){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            binary(n);
            count++;
        }
        n++;
    }
}

/*
Output
000001
000010
000011
000101
000111
001011
001101
010001
010011
010111
011101
011111
100101
101001
101011
101111
110101
111011
*/

/* Hecho con ayuda del libro Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988), al igual que la ayuda de rulgamer03 */ 

  

