#include <stdio.h>

typedef void (*fuctn_ptr)();

void greet(){
    printf("Hello \n");
}

void farewell(){
    printf("Bye \n");
}

int main(){
    fuctn_ptr functions[2];
    
    functions[0] = greet;
    functions[1] = farewell;

    for(int i = 0; i < 2; i++){
        functions[i];
    }
    return 0;
}