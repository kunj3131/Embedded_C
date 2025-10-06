    #include <stdio.h>
    int main(){
        int i = 257;
        int *p;
        p = &i;
        printf("%d \n", i); //value of i
        printf("%p \n", p); //address of i
        printf("%d \n", *p); //value of i
        printf("%p \n", &i); //address of i
        printf("%p \n", &p); //address of p
        printf("%ld \n", sizeof(p));
        printf("%ld \n\n", sizeof(i));


        int *ip;
        char *cp;
        ip = &i;
        cp = (char *)&i;
        printf("%d, %d\n",*ip, *cp); //cp value is based on little endian
        printf("%ld, %ld\n\n",sizeof(ip), sizeof(cp));

        *cp = 'a';
        printf("%d, %d\n", *ip, *cp); //
        printf("%ld, %ld\n\n",sizeof(ip), sizeof(cp));
    }