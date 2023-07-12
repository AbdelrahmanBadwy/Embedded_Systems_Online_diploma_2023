#include <stdio.h>

int reverseDigits(int num) {
    int reversedNum = 0;
    
    while (num != 0) {
        int digit = num % 10;     // Get the rightmost digit
        reversedNum = reversedNum * 10 + digit;     // Append the digit to the reversed number
        num /= 10;     // Remove the rightmost digit from the original number
    }
    
    return reversedNum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int reversedNum = reverseDigits(num);
    printf("Reversed number: %d\n", reversedNum);
    
    return 0;
}
