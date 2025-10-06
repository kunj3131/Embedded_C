#include <stdio.h>

void add(int a, int b){
    printf("add: %d\n", a+b);
}

void sub(int a, int b){
    printf("sub: %d\n", a-b);
}

void mul(int a, int b){
    printf("mul: %d\n", a*b);
}

void div(int a, int b){
    printf("div: %d\n", a/b);
}

void (*operation)(int, int);

int main(){
    int choice = 4, x = 10, y = 5;
    switch (choice)
    {
    case 1:
        operation = add;
        break;
    
    case 2:
        operation = sub;
        break;

    case 3:
        operation = mul;
        break;

    default:
        operation = div;
        break;
    } 
    operation(x,y);
    return 0;
}

