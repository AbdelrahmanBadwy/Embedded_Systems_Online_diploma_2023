#include <stdio.h>

int main() {
    float num1, num2, num3, largest;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    largest = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

    printf("Largest number: %.2f\n", largest);

    return 0;
}
