#include <stdio.h>

int main() {
    int a[3][4] = {
        {15, 27, 11, 35},
        {22, 19, 31, 17},
        {31, 23, 14, 36}
    };
    int *p;               
    p = &a[0][0];

    printf("%d \n", *(p+1));  
    printf("%d \n", *(p+5)); 
    printf("%d \n", *(p+11));
    

    return 0;
}