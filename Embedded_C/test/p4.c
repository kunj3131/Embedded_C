// #include <stdio.h>
// int main(){
//     char str[5] = "Hello";
//     char *p;
//     p = str;
//     printf("String: %s\n", p);
//     while(*p != '\0'){
//         printf("%c ", *p);
//         p++;
//     }
// }


#include <stdio.h>
int main(){
    char str[5]="Hello";
    char *p;
    p = str;
    while(*p != '\0'){
        printf("%c",*p);
        p++;
    }
}