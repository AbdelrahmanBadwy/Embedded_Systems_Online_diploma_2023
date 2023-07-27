#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student students[10];

    // Input information for each student
    printf("Enter information of students:\n");
    for (int i = 0; i < 2; i++) {
        printf("For roll number %d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);

        students[i].roll = i + 1;

        printf("\n");
    }

    // Display the entered data
    printf("Displaying information of students:\n");
    for (int i = 0; i < 2; i++) {
        printf("Information for roll number %d:\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}
