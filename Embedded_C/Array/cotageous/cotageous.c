#include <stdio.h>
int main(){
    int a[5]={1,2,3,4,5}, i;
    for(i=0;i<5; i++){
        // scanf("%d", &a[i]);
        printf("..%p\n", &a[i]);
    }
    printf(".%p\n", &i);
    printf("%d\n", a[-1]);
}