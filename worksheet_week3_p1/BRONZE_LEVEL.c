
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        perror("");
        return 1;
    }

    int data1;
    printf("Type number to get it square root: ");
    scanf("%d", &data1);
    int totaldata = data1*data1;
     fprintf(file, "The square root of your number is: %d\n" ,totaldata);


    fclose(file);
    return 0;
}