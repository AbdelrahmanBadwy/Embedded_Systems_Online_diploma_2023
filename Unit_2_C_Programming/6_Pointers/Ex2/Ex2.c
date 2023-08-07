#include <stdio.h>

int main() {
  char *ptr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  for (int i = 0; i < 26; i++) {
    printf("%c ", *(ptr + i));
  }

  printf("\n");

  return 0;
}
