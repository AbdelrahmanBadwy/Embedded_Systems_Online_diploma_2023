#include <stdio.h>

unsigned long long factorial(unsigned int n);

int main() {
    unsigned int num;

    printf("Enter a non-negative integer: ");
    fflush(stdin);fflush(stdout);
    scanf("%u", &num);

    unsigned long long fact = factorial(num);

    printf("Factorial of %u = %llu\n", num, fact);

    return 0;
}

unsigned long long factorial(unsigned int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    
    // Recursive case: multiply n with factorial of (n-1)
    return n * factorial(n - 1);
}