#include <stdio.h>

int sum_digits(int number) {
  int sum = 0;
  while (number > 0) {
    int digit = number % 10;
    sum += digit;
    number /= 10;
  }
  return sum;
}

int main() {
  int number = 4565;
  int sum = sum_digits(number);
  printf("The sum of the digits of %d is %d\n", number, sum);
  return 0;
}
