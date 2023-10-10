

# include <stdio.h>

int main()
{
    int data1;

    printf ("What's the radius of your circle: ");
    scanf(" %d", &data1);

    int totaldata = data1*data1*3.1416;

    printf("The area of your rectangle is /%d\n" ,totaldata);
}