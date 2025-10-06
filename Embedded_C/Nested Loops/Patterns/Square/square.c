#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) { // Loop for each row
        for (int j = 0; j < 5; j++) { // Loop for each column
            printf("%d ", j); // Print the current row number
        }
        printf("\n"); // Move to the next line after each row
    }
    return 0;
}
