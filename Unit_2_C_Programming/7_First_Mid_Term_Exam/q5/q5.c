#include <stdio.h>

int count_ones(int number) {
  int count = 0;
  while (number > 0) {
    if (number & 1 == 1) {
      count++;
    }
    number >>= 1;
  }
  return count;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int count = count_ones(num);
    printf("The number of ones in %d is %d\n", num, count);
    return 0;
}
