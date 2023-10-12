

# include <stdio.h>

int main() {
    char str[] = "Hello";
    int length = 0;

    // Manually determine the length of the string
    while (str[length] != '\0') {
            length++;
    }

//print the string  in reverse, including the null-terminating character
for (int i = length; i >= 0; i--) {
    if (str[i] == '\0') {
        printf("\\0 ");
    } else {
        printf("%c ", str[i]);
    }
}
    printf("\n");
    return 0;
}