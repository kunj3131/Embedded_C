/*
Reverse Digit
*/
// #include <stdio.h>
// int main(){
//     int num = 123456789, r, reverse;
//     for(reverse = 0; num!=0; num = num/10){
//         r=num%10;
//         reverse = reverse*10 + r;
//     }
//     printf("%d\n", reverse);
// }

/*
Variable
*/

#include "stdio.h"

void variable(unsigned short int i, short int j){
    printf("i\n");
    // scanf("%d", &i);
    printf("%d\n j\n");
    // scanf("%d", &j);
    printf("%d %d\n", i, j);
}

void increment_operator(int a, int c){
    printf("a \n");
    printf("%d\n", a);
    int b = a++;
    printf("%d\n", a);
    printf("%d\n", b);
printf("\n");
    printf("c \n");
    printf("%d\n", c);
    int d = ++c;
    printf("%d\n", c);
    printf("%d\n", d);
}

int main(){
    variable(65536, 32768);
    printf("\n");
    increment_operator(5,5);
}