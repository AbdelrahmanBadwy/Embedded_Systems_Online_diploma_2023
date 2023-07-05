#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char character;

    printf("Enter a string: ");
    gets(str);

    printf("Enter a character to find frequency: ");
    scanf("%c", &character);

    int frequency = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == character) {
            frequency++;
        }
    }

    printf("Frequency of %c = %d\n", character, frequency);

    return 0;
}
