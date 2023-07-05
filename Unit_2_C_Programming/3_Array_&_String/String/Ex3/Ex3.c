#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str);

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[100];

    printf("Enter the string: ");
    gets(str);

    reverseString(str);

    printf("Reverse string is: %s\n", str);

    return 0;
}
