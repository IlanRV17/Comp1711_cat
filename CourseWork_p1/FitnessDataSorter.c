#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buffer_size 100

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

// Function to validate the date and time format
int isValidDateTimeFormat(const char *date, const char *time) {
    // Add your validation logic here
    // For simplicity, this example assumes a date format like "MM-DD-YYYY" and a time format like "HH:MM"
    if (strlen(date) != 10 || date[2] != '-' || date[5] != '-' || strlen(time) != 5 || time[2] != ':') {
        return 0; // Invalid date or time format
    }
    return 1; // Valid date and time format
}

int main() {
    // array of daily readings
    FitnessData daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    FILE *input = fopen(filename, "r");
    if (!input) {
        printf("Error: File could not be opened\n");
        return 1;
    }

    int counter = 0;

    while (fgets(line, buffer_size, input)) {
        // split up the line and store it in the right place
        // using the & operator to pass in a pointer to the bloodIron so it stores it
        char date[11];
        char time[6];
        int steps;

        tokeniseRecord(line, ',', date, time, &steps);

        if (!isValidDateTimeFormat(date, time)) {
            printf("Error: Invalid date or time format in the file\n");
            return 1;
        }

        daily_readings[counter].steps = steps;
        strcpy(daily_readings[counter].date, date);
        strcpy(daily_readings[counter].time, time);

        counter++;
    }

    // Continue with the rest of your code...
    
    return 0;
}