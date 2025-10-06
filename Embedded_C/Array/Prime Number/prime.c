#include <stdio.h>
int main(){
    int a[5]={1,2,3,4,5}, i=0, ele;
    ele = sizeof(a)/sizeof(a[0]);
    for(i;i<ele;i++)
    {
        printf("%d..", a[i]);
        int count=0;
        for(int j=1;j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                count++;
            }
        }
        if(count==2){

            printf("->Prime\n");
        }
        else{
            printf("->Not Prime\n");
        }
    }
}




// int main(){
//     int a[5]={1,2,3,4,5}, i=0, ele, j=1, m=0, c=0;
//     ele = sizeof(a)/sizeof(a[0]);
//     for(i; i<ele; i++){
//         printf("%d-->", a[i]);
//         for(j; j<=a[i]; j++){
//             if(a[i]%j==0){
//                 c++;
//             }
//         }
//         if(c==2){
//             printf("%d prime number\n", a[i]);
//             m++;
//         }
//         else{
//             printf("%d not prime\n", a[i]);
//         }
//     }
//     printf("%d-->total", m);
// }



// #include <stdio.h>

// int main() {
//     int a[5] = {1, 2, 3, 4, 5}, c, i, j, m = 0;
//     int ele = sizeof(a) / sizeof(a[0]);

//     for (i = 0; i < ele; i++) {
//         printf("%d --> ", a[i]);
//         c = 0;
//         for (j = 1; j <= a[i]; j++) {
//             if (a[i] % j == 0) {
//                 c++;
//             }
//         }
//         if (c == 2) {
//             printf("%d prime number\n", a[i]);
//             m++;
//         } else {
//             printf("%d not prime\n", a[i]);
//         }
//     }
//     printf("%d --> total prime numbers\n", m);
//     return 0;
// }
