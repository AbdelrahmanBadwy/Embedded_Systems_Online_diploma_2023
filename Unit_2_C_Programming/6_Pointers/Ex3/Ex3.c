#include <stdio.h>
#include<string.h>

void print_string_in_reverse(char *str) {
  int len = strlen(str);
  char *ptr = str + len;

  for (int i = len ; i >= 0; i--) {
    printf("%c", *ptr--);
  }
}

int main() {
  char str[50];
  printf("Input a string : ");
  scanf("%s", str);

  printf("Reverse of the string is : ");
  print_string_in_reverse(str);

  return 0;
}
