#include <stdio.h>
int main(){

/************************************************
******      Binary of int using float      *******
***************************************************/

    int *ip;
    float f = 3.3;
    ip = (int*)&f;
    printf("%p \n", &ip);
    for(int pos = 31; pos>=0; pos--)
    {
        printf("%d", *ip>>pos&1);
    }
    printf("\n");

/************************************************
******      Binary of char using int       *******
***************************************************/

    char *cp;   //try signed and unsigned here
    int i = 515;
    cp = (char*)&i;
    printf("%d\n", *cp);
    printf("%ld\n", sizeof(*cp));
    for(int pos = 7; pos>=0; pos--)
    {
        printf("%d", *cp>>pos&1);
    }
}