#include <stdio.h>
int main(){
    int i=10, j;
    int *p = &i;
    printf("%d\n", p);
    printf("%p\n", p);
    j=*p++;
    printf("%d\n", p);
    printf("%p\n", p);
    printf("i: %d j: %d\n", i, j);
    j=++*p;
    printf("%d\n", p);
    printf("%p\n", p);
    printf("i: %d j: %d\n", i, j);
    j=*p++;
    printf("%d\n", p);
    printf("%p\n", p);
    printf("i: %d j: %d\n", i, j);
}