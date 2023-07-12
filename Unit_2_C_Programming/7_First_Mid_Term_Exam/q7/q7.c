#include <stdio.h>

int sum_numbers(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n + sum_numbers(n - 1);
  }
}

int main() {
  int sum = sum_numbers(100);
  printf("The sum of the numbers from 1 to 100 is %d\n", sum);
  return 0;
}
