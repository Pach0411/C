#include <stdio.h>
#define START 56
#define STOP 13
#define MOD 2
int main() {
    int i = START;
    int count = 0;
    do{
        if(i % MOD == 0){
            count /=2;
            continue;
        }
        ++count;
    }while (i-- > STOP);
    printf("%d\n", count);
}



