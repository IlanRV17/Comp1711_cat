# include <stdio.h>

float sum(float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main (){

    float x = 5;
    float y = 2;
    float z = sum(x, y);

    printf ("The sum of %.2f and %.2f is %.2f\n", x, y, z);
    }