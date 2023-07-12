#include <stdio.h>

int is_prime(int number) {
  if (number <= 1) {
    return 0;
  }
  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}

void print_primes(int n1, int n2) {
  for (int i = n1; i <= n2; i++) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
}

int main() {
  int n1,n2;
  printf("Enter two integer numbers: ");
  scanf("%d %d", &n1,&n2);  
  print_primes(n1, n2);
  return 0;
}
