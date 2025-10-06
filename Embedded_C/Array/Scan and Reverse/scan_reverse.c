// #include <stdio.h>
// int main(){
//     int i,a[10];
//     for(i=0; i<10; i++){
//         printf("%d-->",i);
//         scanf("%d",&a[i]);
//     }
//     for(i=9,a[i]; i>=0; i--){
//         printf("%d --> %d\n",i, a[i]);
//     }
// }

#include <stdio.h>
int main(){
    int i, a[5], j;
    for(i=0;i<5;i++){
        printf("enter");
        scanf("%d",&a[i]);
    }
    for(j=5;j>0;j--){
        printf("%d\n",a[j-1]);
    }
}