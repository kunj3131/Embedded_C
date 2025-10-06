#include<stdio.h>
// #include<string.h>
int main(){
    char a[] = {'a','b','c','d'};
    char s[] = {"Hello World"};
    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(s));
    printf("%s\n", s);

    char b[5];
    scanf("%s", b);     //not need to use "&" at &b
    printf("%s\n", b);

    // for(int i=0; i<(sizeof(s)/sizeof(s[0])); i++){
    for(int i=0; s[i]!='\0'; i++){
        printf("%c\n", s[i]);
    }
}