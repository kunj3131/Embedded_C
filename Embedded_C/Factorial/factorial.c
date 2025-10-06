// #include <stdio.h>
// int main(){
//     int num = 9, a=0;   // a = 1;
//     a = num-1;          // Not Required
//     for(a; a>=1; a--){  // for(a;a<=num;a++)
//         printf("%d-->", a);
//         num = num*a;
//         printf("%d\n", num);
//     }
//     printf("%d\n", num);
// }

#include <stdio.h>

int multi(int n){
    if(n>=1)
        return n*multi(n-1);
    else
        return 1;
}

int main() {
    int n = 9, r = 1;
    for (int i = 1; i <= n; i++) {
        r = r * i;
    }
    printf("simple %d\n", r);
    printf("recursion %d\n",multi(n));
    return 0;
}
