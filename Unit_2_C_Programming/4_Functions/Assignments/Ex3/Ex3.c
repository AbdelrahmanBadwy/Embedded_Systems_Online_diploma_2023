#include <stdio.h>

void Reverse();

int main() {
  printf("Enter the sentence : ");
  Reverse();
}

void Reverse(){
    char c ;
    scanf("%c",&c);
    if (c != '\n')
    {
        Reverse();
        printf("%c",c);
    }
}