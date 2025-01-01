#include <stdio.h>

#define SET_BIT(Variable, bit_position)    Variable |= (1<< bit_position) 
#define CLEAR_BIT(Variable, bit_position)    Variable &= ~(1<< bit_position) 
#define TOGGLE_BIT(Variable, bit_position)    Variable ^= (1<< bit_position) 
#define CHECK_BIT_IS_SET_OR_NOT(Variable, bit_position)    Variable & (1<< bit_position)

int SetPerticularBit(int a, int position){
    a = a | (1 << position);
    return a;
}

int ClearPerticularBit(int a, int position){
    a = a & ~(1 << position);
    return a;
}

int TogglePerticularBit(int a, int position){
    a = a ^ (1 << position);
}

int CheckSetPerticularBit(int a, int position){
    if((a & (a << position)) == 0){
        printf("bit is not set");
    }
    else {
        printf("Bit is set");
    }
}

int main(){
    int a = 4, b = 6;
    printf("%d \n", SetPerticularBit(4, 1));

    printf("%d \n", SET_BIT(a,1));

    printf("%d \n", CheckSetPerticularBit(6, 1));

    printf("%d \n", CHECK_BIT_IS_SET_OR_NOT(b,1));

    printf("%d \n", ClearPerticularBit(4, 1));

    printf("%d \n", CLEAR_BIT(a,1));

    printf("%d \n", TogglePerticularBit(4, 1));

    printf("%d \n", TOGGLE_BIT(a,1));
}