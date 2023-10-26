
#include <stdio.h>
#include "utils.h"
#include "utils.h"


int main() {
    FILE *afile = open_file("data.txt", "r");
    
    int number, num_lines = 10;
    printf("Type %d numbers: ", num_lines);
    
    for (int i = 0; i < num_lines; i++) {
        scanf("%d", &number);
        fprintf(afile, "%d\n", number);
    }

    fclose(afile);
    return 0;
}