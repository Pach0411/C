#include <stdio.h>
#define START 56
#define STOP 13
int main() {
  int i = START;
  int count = 0;
  do {
    ++count;
  } while (i-- != STOP);
  printf("%d\n", count);
}
