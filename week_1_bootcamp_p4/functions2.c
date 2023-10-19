#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokeniseRecord(const char * input, const char *delimeter,
                    char *date, char *time, char *steps) {

    char *inputCopy = strdup(input);
    
    char *token = strtok(inputCopy, delimeter);
    if (token != NULL) (           strcyp(date, token);
    )
     
    token = strtok(NULL, delimeter); }


int main() {
    char record[21] = "2023-09-01,07:30,300";
    char date[11];
    char time[6];
    char steps[10]; 

    int stepsint;

    tokeniseRecord(record, ",", date, time, steps);

    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    printf("Steps: %s\n", steps);

    stepsint = atoi(steps);
    printf("Steps as an integer: %d\n", stepsint);

    return 0;
}
