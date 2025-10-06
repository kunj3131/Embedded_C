// #include <stdio.h>
// int main(){
//     int a[5] = {8,2,10,15,15}, i, max, b=0, second_max;
//     for(i=0; i<(sizeof(a)/sizeof(a[0])); i++){
//         if(max<a[i]){
//             second_max = max;
//             max = a[i];
//         }
//     }
//     printf("%d\n", max);
//     printf("%d\n", second_max);
// }

#include <stdio.h>
int main(){
    int i=0,a[5]={5,3,99,9,23},ele, max=0, second=0;
    ele = sizeof(a)/sizeof(a[0]);
    for (i = 0; i < ele; i++) {
        if (a[i] > max) {
            second = max; 
            max = a[i]; 
        } 
        else if (a[i] > second && a[i] != max) { 
            second = a[i];
        }
    }
    printf("%d\n", max);
    printf("%d\n", second);
}