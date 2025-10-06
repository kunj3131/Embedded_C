#include <stdio.h>
int main(){
    int num = 121, num1 = 0, r, palindrome;
    num1 = num;
    for(palindrome = 0; num; num = num/10){
        r =num % 10;
        palindrome = palindrome * 10 + r;
    }
    if(num1 == palindrome){
        printf("number is palindrome \n");
    }
    else
        printf("number is not palindrome \n");
}