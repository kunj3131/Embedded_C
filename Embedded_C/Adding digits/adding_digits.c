//Reverse Digit 4567 -> 7654

#include <stdio.h>
int main(){
    int num = 123, r, sum = 0;
    for(sum = 0; num; num = num/10){
        r = num%10;
        printf("%d", r);
        sum = sum + r;          //reverse
    }
    printf("\n %d \n", sum);   //sum
}