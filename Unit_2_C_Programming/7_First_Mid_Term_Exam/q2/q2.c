#include <stdio.h>
#include <math.h>

float calculateSquareRoot(int number) {
    float squareRoot = sqrt(number);
    return squareRoot;
}

int main() {
    int number;
    printf("Enter an integer number: ");
    scanf("%d", &number);
    
    float result = calculateSquareRoot(number);
    printf("The square root of %d is %.3f\n", number, result);
    
    return 0;
}
