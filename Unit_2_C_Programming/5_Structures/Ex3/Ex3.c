#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

int main() {
    struct Complex c1, c2, sum;

    // Input information for the first complex number
    printf("For 1st complex number\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f", &c1.real, &c1.imag);

    // Input information for the second complex number
    printf("\nFor 2nd complex number\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f", &c2.real, &c2.imag);

    // Add the complex numbers
    sum = addComplex(c1, c2);

    // Display the sum of complex numbers
    printf("\nSum = %.1f + %.1fi\n", sum.real, sum.imag);

    return 0;
}
