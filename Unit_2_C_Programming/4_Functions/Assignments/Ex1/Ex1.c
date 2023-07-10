#include <stdio.h>


void primesInInterval(int start , int end);

int main() {
    int s, e;

     // Prompt user to enter two numbers
    printf("Enter two numbers: ");
    fflush(stdin);
    fflush(stdout);
    
    // Read the input numbers from the user
    scanf("%d %d", &s, &e);
    fflush(stdin);
    fflush(stdout);

    primesInInterval(s,e);
    
    return 0;
}

void primesInInterval(int start , int end){

    unsigned char notPrime; // flag to indicate if a number is not prime

    // Display the message for prime numbers in the given range
    printf("Prime numbers between %d and %d: ", start, end);
    
    // Iterate through each number in the range
    for (int i = start; i <= end; i++) {
        notPrime = 0; // Assume the number is prime initially

        // Check if the number is divisible by any number from 2 to i/2
        for (int j = 2; j < i / 2; j++) {
            if (i % j == 0) {
                notPrime = 1; // Set the flag indicating the number is not prime
                break; // No need to check further, exit the loop
            }
        }
        
        // If the number is prime (flag is still 0), print it
        if (!notPrime) {
            printf("%d \t", i);
        }
    
    
}


}