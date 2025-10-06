// #include <stdio.h>
// int main(){
//     char *fruits[3] = {"apple", "banana", "cherry"};
//     int num_fruits = sizeof(fruits)/sizeof(fruits[0]);
//     for(int i = 0; i < num_fruits ;i++){
//         printf("%s \n", fruits[i]);
//     }
// }

#include <stdio.h>
int main(){
    char *str[3] = {"fruit","vegetable","human"};
    int ele = sizeof(str)/sizeof(str[0]);
    for(int i=0;i<ele;i++){
        printf("%s\n",str[i]);
    }
}