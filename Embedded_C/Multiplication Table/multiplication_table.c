#include <stdio.h>
int main(){
    int num, i;
    printf("Enter no. \n");
    scanf("%d", &num);
    for(i = 1; i <= 10; printf("%d * %d = %d\n", num, i, num*i), i++);
}