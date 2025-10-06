//printing an array, transpose, max number

#include <stdio.h>
int main() {
    int array[3][4], transpose[4][3], max=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("Enter element for [%d][%d] : ",i,j);
            scanf("%d", &array[i][j]);
        }
    }
    printf("output\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            transpose[j][i] = array[i][j];
        }
    }
    printf("output\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(array[i][j]>max){
                max=array[i][j];
            }
            else{
                array[i][j];
            }
        }
    }
    printf("max %d: \n", max);
    
    return 0;
}