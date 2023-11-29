#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int array1[3][4];
    int array2[3][4]; // Define both Arrays
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Assign random values to each element of the array
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            array1[i][j] = rand() % 11; // rand() % 11 gives a range 0 to 10
        }
    }

    printf("First Array: \n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", array1[i][j]); // Create first Array
        }
        printf("\n");
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            array2[i][j] = rand() % 11; // rand() % 11 gives a range 0 to 10
        }
    }   

    printf("Second Array: \n");

    // Print the array to verify
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", array2[i][j]); // Create second Array
        }
        printf("\n");
    }

    printf("Multiply Arrays: \n");
    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", array1[i][j]*array2[i][j]); // Multiply both Arrays to get the final value
        }
        printf("\n");
    }


    return 0;
}