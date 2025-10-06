// #include <stdio.h>
// int fibonacci(){
//     int c = 1;
//     int a = 1, b = 1;
//     for(int i = 0; i < 20; i++){
        
//         c = a + b;
//         printf("%d \n", a);
//         a =b;
//         b =c;

//         i++;
//     }
// }

// int main(){
//     fibonacci();
//     return 0;
// }


#include <stdio.h>

int fibo(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main(){
    int a=1,b=0,c=0;
    for(int i=0;i<10;i++){
        c=a+b;
        printf("simple %d\n", c);
        b=a;
        a=c;
    }
    printf("recursive %d\n",fibo(10));
}