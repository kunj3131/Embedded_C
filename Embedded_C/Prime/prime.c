#include <stdio.h>
int main(){
    int num = 3, i,c=0;
    for(i=1; i<=num;i++){
        if(num%i==0)
        c++;
    }
    if(c==2)
    printf("numeber is prime\n");
    else
    printf("not prime\n");
    
}
