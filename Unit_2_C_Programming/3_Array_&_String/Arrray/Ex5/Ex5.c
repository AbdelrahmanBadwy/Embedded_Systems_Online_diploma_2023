#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int element;
    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    int location = -1; // Initialize location to -1

    // Search for the element in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            location = i + 1; // Store the location (index + 1) of the element
            break; // Exit the loop once the element is found
        }
    }

    if (location != -1) {
        printf("Number found at the location = %d\n", location);
    } else {
        printf("Number not found in the array.\n");
    }

    return 0;
}
