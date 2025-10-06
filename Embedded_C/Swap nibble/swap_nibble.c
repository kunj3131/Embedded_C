#include <stdio.h>
#define SWAP_N(x)       (((x&0x0F)<<4) | ((x&0xF0)>>4))

int main() {
    unsigned int num = 177;
    num &= 0xFF; 
    num = ((num & 0x0F) << 4) | ((num & 0xF0) >> 4);

    printf("Swapped nibbles: %d\n", num);
    
    printf("Swapped binary: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");

    printf("Size of num: %ld bytes\n", sizeof(num));
    
    char b,a=0x27;
    b=SWAP_N(a);
    printf("%x\n",b);

    return 0;

}

    // unsigned char num = 177;
    // num = (num>>28)|(num<<4);
    // printf("%ld\n", sizeof(num));
    // printf("%d\n", num);


// 0000 0000 - 0000 0000 - 0000 0000 - 1011 0001
// 0000 0000 - 1011 0001 - 0000 0000 - 0000 0000
