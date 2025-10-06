#include <stdio.h>
int main(){
    int num = 12, i, j, m, n, pos;
    for(pos=7; pos>=0; pos--)
    printf("%d", num>>pos&1);
    printf("\n");
    for(i=0,j=7;i<=j;i++,j--){
        m=num>>i&1;
        printf("%d",m);
        printf("\n");
        n=num>>j&1;
        if(m!=n){
            num = num^1<<i;
            num = num^1<<j;   
        }
    }
    printf("%d", num);
    printf("\n");
    // printf("%d",num);
    for(pos=7;pos>=0;pos--)
    printf("%d", num>>pos&1);
    printf("\n");
    // }
}