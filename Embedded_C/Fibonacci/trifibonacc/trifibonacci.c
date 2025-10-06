// // #include <stdio.h>

// // int trifibonacci(){
// //     int a = 0, b = 0, c = 1, d = 0;
    
// //     for(int i = 0; i < 10; i++){
// //         a = d;
// //         d = a + b + c;
// //         c = b;
// //         b = a;
// //         printf("%d \n", d);
// //     }
// // }

// // int main(){
// //     trifibonacci();
// //     return 0;
// // }
// #include <stdio.h>

// void trifibonacci() {  // Changed return type to void since nothing is returned
//     int a = 0, b = 0, c = 1, d = 0;

//     // Print the initial three terms
//     printf("%d\n", a);
//     printf("%d\n", b);
//     printf("%d\n", c);

//     // Generate the next 10 terms
//     for (int i = 0; i < 10; i++) {
//         d = a + b + c;
//         printf("%d\n", d);

//         // Update the variables for the next iteration
//         a = b;
//         b = c;
//         c = d;
//     }
// }

// int main() {
//     trifibonacci();
//     return 0;
// }


#include <stdio.h>

int tri(int n){
    if(n<=1){
        return n;
    }
    else{
        return tri(n-1)+tri(n-2)+tri(n-3);
    }
}
int main(){
    int a=1,b=0,c=0,d=0;
    for(int i=0;i<5;i++){
    d = a+b+c;
    printf("simple %d\n", d);
    c=b;
    b=a;
    a=d;
    }
    printf("recursion %d\n",tri(5));
}