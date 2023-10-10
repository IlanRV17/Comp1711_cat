

# include <stdio.h>

int main()
{
    int data1;
    int data2;

    printf ("Select your first number you want to add ");
    scanf(" %d", &data1);
    printf ("Now select your second number to add: ");
    scanf(" %d", &data2);
    int totaldata = data1+data2;

    printf("The area of your rectangle is /%d\n" ,totaldata);
}