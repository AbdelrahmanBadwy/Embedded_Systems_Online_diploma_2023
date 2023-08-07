#include <stdio.h>

void print_array_in_reverse(int *arr, int size) {
  int i;

  for (i = size - 1; i >= 0; i--) {
    printf("element - %d : %d\n", i + 1, arr[i]);
  }
}

int main() {
  int arr[15];
  int size, i;

  printf("Input the number of elements to store in the array (max 15) : ");
  scanf("%d", &size);

  printf("Input %d number of elements in the array :\n", size);
  for (i = 0; i < size; i++) {
    printf("element - %d : ", i + 1);
    scanf("%d", &arr[i]);
  }

  printf("The elements of array in reverse order are :\n");
  print_array_in_reverse(arr, size);

  return 0;
}
