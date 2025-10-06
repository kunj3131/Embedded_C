#include <stdio.h>
// int main(){
//    int x = 0x11223344, y=0;
//    y |= ((0x000000FF & x)<<24);
//    y |= ((0x0000FF00 & x)<<8);
//    y |= ((0x00FF0000 & x)>>8);
//    y |= ((0xFF000000 & x)>>24);
//    printf("%x\n", x);
//    printf("%x", y);
// }
int main(){
   int a=0x1;
   char *r=(char*)&a;
   if(*r==1){
      printf("little");
   }
   else{
      printf("big");
   }
}