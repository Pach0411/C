#include<stdio.h>
int main() {
  float x = 1.337;
  int y = 20;
  while (x <= y) {
    x = x / 4;
    y = y * x;
  }
  printf("%.2f, %d\n", x, y);
}