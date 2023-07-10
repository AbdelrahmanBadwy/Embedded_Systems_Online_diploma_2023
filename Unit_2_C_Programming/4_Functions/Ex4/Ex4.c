#include <stdio.h>

double power(double base, int exponent);

int main() {
    double base;
    int exponent;

    printf("Enter the base number: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);

    printf("%.2lf ^ %d = %.2lf\n", base, exponent, result);

    return 0;
}

double power(double base, int exponent) {
    // Base case: exponent is 0, result is 1
    if (exponent == 0) {
        return 1;
    }
    
    // Recursive case: multiply base with power(base, exponent-1)
    return base * power(base, exponent - 1);
}