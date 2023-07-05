#include <stdio.h>
#include<string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    printf("Length of string: %d\n", length);

    return 0;
}
