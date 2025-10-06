//Armstrong cube of the digit 

// #include <stdio.h>
// int main(){
//     int num = 1634, i, sum=0, arm = 0;
//     arm = num;
//     while(num>0){
//         i = num%10;
//         printf("1-> %d\n", i);
//         sum = sum+(i*i*i*i);
//         num = num/10;
//     }
//     printf("%d", sum);
//     if(arm == sum)
//     printf("Armstrong");
//     else
//     printf("not");
// }





//  Number is armstrong or not


#include <stdio.h>

int main() {
    int num = 153, n, digit=0, rem=0, sum=0;
    n = num;
    while(n!=0){
        n = n / 10;
        digit++;
    }
    n = num;
    while(n!=0){
        rem = n % 10;
        int power = 1;
        for(int i=0;i<digit;i++){
            power = power*rem;
        }
        sum = power + sum;
        n = n /10;
    }
    if(sum==num){
        printf("Arm");
    }
    else{
        printf("not");
    }
    return 0;
}
