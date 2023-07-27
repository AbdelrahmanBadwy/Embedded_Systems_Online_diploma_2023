#include <stdio.h>

struct Distance {
    int feet;
    float inch;
};

struct Distance addDistances(struct Distance d1, struct Distance d2) {
    struct Distance sum;

    sum.feet = d1.feet + d2.feet;
    sum.inch = d1.inch + d2.inch;

    if (sum.inch >= 12.0) {
        sum.inch -= 12.0;
        sum.feet++;
    }

    return sum;
}

int main() {
    struct Distance d1, d2, sum;

    printf("Enter information for 1st distance\n");
    printf("Enter feet: ");
    scanf("%d", &d1.feet);
    printf("Enter inch: ");
    scanf("%f", &d1.inch);

    printf("\nEnter information for 2nd distance\n");
    printf("Enter feet: ");
    scanf("%d", &d2.feet);
    printf("Enter inch: ");
    scanf("%f", &d2.inch);

    sum = addDistances(d1, d2);

    
    printf("\nSum of distances = %d' - %.1f\n", sum.feet, sum.inch);

    return 0;
}
