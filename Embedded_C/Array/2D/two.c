//calculate sum of array
#include <stdio.h>

int main() {
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int sum = 0;

    // Calculate the sum of elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += array[i][j];
        }
    }

    printf("Sum of elements: %d\n", sum);
    return 0;
}