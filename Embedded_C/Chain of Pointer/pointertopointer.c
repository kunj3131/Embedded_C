#include <stdio.h>
int main(){
    int x, y, *p1, **p2;
    x = 10;
    p1 = &x;
    p2 = &p1;
    printf("%d\n", x);
    printf("%d\n", *p1);
    printf("%d\n", **p2);
}