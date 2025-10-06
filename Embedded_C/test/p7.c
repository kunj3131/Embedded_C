#include <stdio.h>
int *larger(int *x, int *y){
    if(*x > *y){
        return(x);
    }
    else{
        return(y);
    }
}

int main(){
    int a = 100;
    int b = 20;
    int *p;
    p = larger(&a, &b);
    printf("%d\n", *p);
}