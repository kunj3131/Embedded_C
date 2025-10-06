#include <stdio.h>
int main(){
    int *p, sum, i;
    int x[5] = {5, 9, 6, 3, 7};
    i = 0;
    p = &x[0];
    printf("Element value Address \n");
    while(i < 5){
        printf("x[%d] %d %p\n", i, *p, p);
        sum = sum + *p;
        i++, p++;
    }
    printf("\n sum = %d\n", sum);
    printf("\n &x[0] = %p \n", &x[0]);
    printf("\n p = %p \n", &p);
}