//Addition nd Substraction

#include <stdio.h>
int main() {
    int a[3][4] = {{1,2,3,4},
                {5,6,7,8},
                {9,0,1,2}};
    int b[3][4] = {{1,2,3,4},
                {5,6,7,8},
                {9,0,1,2}};
    int c[3][4] = {0};
                
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            c[i][j]=a[i][j]+b[i][j]; 
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            c[i][j]=a[i][j]-b[i][j]; 
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}


//Multiplication
//3x4
#include <stdio.h>

int main() {
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2}
    };
    
    int b[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {0, 1, 2}
    };
    
    int c[3][3] = {0};
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//3x3
#include <stdio.h>

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {5, 6, 7},
        {9, 0, 1}
    };
    
    int b[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int c[3][3] = {0};
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//2x2
#include <stdio.h>

int main() {
    int a[2][2] = {
        {1, 2},
        {5, 6}
    };
    
    int b[2][2] = {
        {1, 2},
        {4, 5}
    };
    
    int c[2][2] = {0};
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}


