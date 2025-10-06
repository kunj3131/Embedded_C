#include <stdio.h>
int main(){
    int a, b, *p1, *p2, x, y, z;
    a = 12;
    b = 4;
    p1 = &a;
    p2 = &b;
    x = *p1 * *p2 - 6;
    y = 4* - *p2 / *p1 + 10;
    printf("Address of a = %p \n", &p1);
    printf("value of a = %d \n", *p1);
    p1++;
    printf("Address of b = %p \n", p1);
    printf("value of b = %d \n", *p1);
    printf("Address of b = %p \n", p2);
    printf("value of b = %d \n", *p2);
    printf("a = %d, b = %d\n x = %d, y = %d\n", a, b, x, y);
}