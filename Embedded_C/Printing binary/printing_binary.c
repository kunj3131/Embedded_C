#include <stdio.h>
void main(){
    int num = 5;
    for(int pos=7;pos >= 0; pos--){
        printf("%d", num >> pos & 1);
    }
    printf("\n");
}