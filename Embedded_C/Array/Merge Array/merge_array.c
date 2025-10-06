#include <stdio.h>
int main(){
    int a[5]={10,20,30,40,50}, b[5]={60,70,80,90,100}, i;
    int ele_a = sizeof(a)/sizeof(a[0]);
    int ele_b = sizeof(b)/sizeof(b[0]);
    i = ele_a + ele_b;
    int c[i], m, n;
    // printf("%d\n", ele_a);
    for(m=0; m<ele_a;m++){ 
        c[m]=a[m];
        printf("%d\n", c[m]);
    }
    for(n=0;n<ele_b;n++){
        c[ele_a+n]=b[n];
        printf("%d\n", c[m+n]);
    }
    for(i=0;i<10;i++){
        printf("...%d\n", c[i]);
    }
}