#include <stdio.h>
int main() {
  int i;
  for (i = 36; i >= 5; i = i - 3);
  printf("%d\n", i);
}