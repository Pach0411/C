#include <stdio.h>
#define FROM 5
#define TO 34
#define STEP 4
#define EVEN 0
int parity(int v);
int main() {
  int j;
  int count = 0;
  for (j = FROM; j < TO; j = j + STEP) {
    if (parity(j) == EVEN) {
       count = count + 1;
    }
  }
  printf("%d\n", count);
}
int parity(int v) {
  return v % 2;
}
