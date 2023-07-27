#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s;

    // Input data from the user
    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);

    printf("Enter student roll number: ");
    scanf("%d", &s.roll);

    printf("Enter student marks: ");
    scanf("%f", &s.marks);

    // Clear the input buffer
    while (getchar() != '\n');

    // Display the entered data
    printf("\nStudent Information:\n");
    printf("Name: %s", s.name);
    printf("Roll Number: %d\n", s.roll);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}
