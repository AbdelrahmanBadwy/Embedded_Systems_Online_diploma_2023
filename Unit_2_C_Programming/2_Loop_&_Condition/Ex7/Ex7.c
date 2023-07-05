#include <stdio.h>

unsigned long long factorial(int n);

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    } else {
        unsigned long long result = factorial(n);
        printf("Factorial: %llu\n", result);
    }

    return 0;
}
// Some Recursion ^_-
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
