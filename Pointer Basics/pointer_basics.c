#include <stdio.h>

int main(){
    int a = 6, b = 4;
    int *ptra, *ptrb; //Derferencing Operator "*"
    printf("Before assign, address of ptra: %p and ptrb: %p \n", ptra, ptrb);
    printf("Adress of variables a: %p and b: %p\n",&a, &b);
    printf("variables a: %d and b: %d\n",a, b);
    //Assign Address
    ptra = &a; //Address Operator: "&"
    ptrb = &b;
    printf("After assign addresses ptra: %p and ptrb: %p \n", ptra, ptrb);
    printf("address of a: %p and b: %p \n", &a, &b);
    return 0;
}