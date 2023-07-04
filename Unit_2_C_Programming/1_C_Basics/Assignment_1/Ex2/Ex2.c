#include<stdio.h>

int main(){
    int theIntger;
    printf("Enter a integer: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&theIntger);
    fflush(stdin);fflush(stdout);
    printf("You entered: %d",theIntger);
    return 0;
}