#include <stdio.h>

int main() {
  int array[] = {1, 2, 3, 4, 5};
  int size = sizeof(array) / sizeof(array[0]);
  for (int i = size-1; i >=0; i--) {
    printf("%d ", array[i]);
  }
  return 0;
}
