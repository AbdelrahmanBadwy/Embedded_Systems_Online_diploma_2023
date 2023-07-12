#include <stdio.h>

int findUniqueNumber(int arr[], int size) {
    int uniqueNumber = arr[0];

    for (int i = 1; i < size; i++) {
        uniqueNumber ^= arr[i];
    }

    return uniqueNumber;
}
//This is not the optimal solution 
int main() {
    int a[] = {4,2,5,2,5,7,4};
    int result = findUniqueNumber(a,7);
    printf("output: %d \n",result);

    int b[] = {4,2,4};
    int result2 = findUniqueNumber(b,3);
    printf("output: %d",result2);
}