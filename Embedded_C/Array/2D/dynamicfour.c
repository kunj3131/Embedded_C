//Double pointer
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int rows, cols;
//     printf("Enter no. of rows ");
//     scanf("%d", &rows);
    
//     printf("Enter no. of cols ");
//     scanf("%d", &cols);
    
//     int **array = (int **)malloc(rows * sizeof(int *));
//     for(int i=0;i<rows;i++){
//         array[i] = (int *)malloc(cols * sizeof(int));
//     }
    
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<cols;j++){
//             printf("values [%d][%d] ",i,j);
//             scanf("%d",&array[i][j]);
//         }
//     }
    
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<cols;j++){
//             printf("%d ",array[i][j]);
//         }
//         printf("\n");
//     }
    
    
//     return 0;
// }



//Single pointer

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter no. of rows ");
    scanf("%d", &rows);
    
    printf("Enter no. of cols ");
    scanf("%d", &cols);
    
    int *array = (int *)malloc(rows * cols * sizeof(int));
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("enter values [%d][%d] ",i,j);
            scanf("%d", &array[i*cols+j]);
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",array[i*cols+j]);
        }
        printf("\n");
    }
    
    return 0;
}
