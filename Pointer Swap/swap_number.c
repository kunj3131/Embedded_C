#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void SwapUsingAdditon(int *p1, int *p2){
    *p1 = *p1 + *p2;
    printf("%d, %p\n", *p1, &p1);
    *p2 = *p1 - *p2;
    printf("%d, %p\n", *p2, &p2);
    *p1 = *p1 - *p2;
    printf("%d, %p\n", *p1, &p1);
}

void SwapUsingMultiplication(int *p1, int *p2){
    *p1 = *p1 * *p2;
    printf("%d, %p\n", *p1, &p1);
    *p2 = *p1 / *p2;
    printf("%d, %p\n", *p2, &p2);
    *p1 = *p1 / *p2;
    printf("%d, %p\n", *p1, &p1);
}

void SwapUsingThirdPointer(int *p1, int *p2){
    int temp = *p1;
    printf("%d, %p\n", temp, &temp);
    *p1 = *p2;
    printf("%d, %p\n", *p1, &p1);
    *p2 = temp;
    printf("%d, %p\n", *p2, &p2);
}

void SwapUsingGenericPointer(int *p1, int *p2, int size){
    void* ptr = malloc(size);
    memcpy(ptr, p1, size);
    // printf("%d, %p\n", *ptr, &ptr);
    memcpy(p1, p2, size);
    printf("%d, %p\n", *p1, &p1);
    memcpy(p2, ptr, size);
    printf("%d, %p\n", *p2, &p2);
}

int main(){
    int a = 5;
    int b = 3;
    printf("%p, %p\n",&a,&b);
    SwapUsingThirdPointer(&a, &b);
    printf("%d, %d\n",a,b);
    printf("%p, %p\n",&a,&b);

    printf("\n\n\n");

    printf("%p, %p\n",&a,&b);
    SwapUsingAdditon(&a, &b);
    printf("%d, %d\n",a,b);
    printf("%p, %p\n",&a,&b);

    printf("\n\n\n");

    printf("%p, %p\n",&a,&b);
    SwapUsingMultiplication(&a, &b);
    printf("%d, %d\n",a,b);
    printf("%p, %p\n",&a,&b);
    
    printf("\n\n\n");

    printf("%p, %p\n",&a,&b);
    SwapUsingGenericPointer(&a, &b, 4);
    printf("%d, %d\n",a,b);
    printf("%p, %p\n",&a,&b);
}