#include<stdio.h>
int main(){
    int a[5] = {10,20,30,40,50}, b[5];
    int ele = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<ele;i++){
        b[i] = a[i];
        printf("%d \n", a[i]);
    }

    /*********************************
     ********* Reverse Array *********
     *********************************/
    for(ele-1;ele>0;ele--){
        printf(".. %d \n", b[ele-1]);
    }
}