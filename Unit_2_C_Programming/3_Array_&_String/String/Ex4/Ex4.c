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

    int element, location;
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);
    printf("Enter the location: ");
    scanf("%d", &location);

    // Shift elements to the right to make space for the new element
    for (int i = n; i >= location; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified location
    arr[location - 1] = element;

    // Increment the number of elements in the array
    n++;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
