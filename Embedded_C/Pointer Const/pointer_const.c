#include <stdio.h>
int main(){
    int *const p, i=20;   //int *const p -> p=&i not work and *p=21 value can give : p not change | *p can change
    // p = &i;            //int const *p & const int *p -> p=&i work and *p=21 value can't assign : p can change | *p not change
    printf("%d\n", i);    //const int *const p  we can not change p and *p
    printf("%p\n",&p);
    printf("%d\n",*p);
    *p=21;
    *p=*p+1;
    printf("%d\n", i);
    printf("%p\n",&p);
    printf("%p\n",&p+1);
    printf("%d\n",*p+1);
}