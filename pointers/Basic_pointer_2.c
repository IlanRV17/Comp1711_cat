#include <stdio.h>

int lets_get_serious()
{
    return 0;
}

int main()
{
    printf("\nEven functions have address. \n");

    printf("The address of main function = %p \n", (void *)main);

    printf("The address of lets_get_serious function = %p \n \n", (void *)lets_get_serious);

    
}