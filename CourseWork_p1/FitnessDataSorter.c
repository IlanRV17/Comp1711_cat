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
    // Assuming a date format like "YYYY-MM-DD" and a time format like "HH:MM"
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-' || strlen(time) != 5 || time[2] != ':') {
        return 0; // Invalid date or time format
    }
    return 1; // Valid date and time format
}

// Compare function for qsort
int compareFitnessData(const void *a, const void *b) {
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;
}

int main() {
    // array of daily readings
    FitnessData daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    printf("Please enter the name of the data file: ");

    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    FILE *input = fopen(filename, "r");
    if (!input) {
        printf("Error: File could not be opened\n");
        return 1;
    }

    int counter = 0;

    while (fgets(line, buffer_size, input)) {
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

    fclose(input);

    // Sort the data
    qsort(daily_readings, counter, sizeof(FitnessData), compareFitnessData);

    // Write the sorted data to a new file with .tsv extension
    strcat(filename, ".tsv");
    FILE *output = fopen(filename, "w");
    if (!output) {
        printf("Error: Unable to create the output file\n");
        return 1;
    }

    // Write sorted data to the file
    for (int i = 0; i < counter; i++) {
        fprintf(output, "%s\t%s\t%d\n", daily_readings[i].date, daily_readings[i].time, daily_readings[i].steps);
    }

    fclose(output);

    printf("Sorting and writing to %s successful.\n", filename);

    return 0;
}