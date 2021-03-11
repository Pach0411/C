#include <stdio.h>
#define START 56
#define STOP 13
#define MOD 2
int main(){
    int i=START;
    int count = 0;
    do{
        ++count;
        if(count % MOD ==0){
            break;
        }
    } while (i-- != STOP);
    printf("%d\n", count);
}
