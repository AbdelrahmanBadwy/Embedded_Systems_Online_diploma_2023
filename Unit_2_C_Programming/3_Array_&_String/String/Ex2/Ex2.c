#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Assume The max Numbers is 10000
    int numbers[10000];
    int sum = 0;

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    double average = (double)sum / n;

    printf("The average is: %.2lf\n", average);

    return 0;
}
