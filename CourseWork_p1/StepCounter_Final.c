#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"


// Struct moved to header file

// Define any additional variables here

// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }
// Complete the main function
int main()
{

    char choice;
    int counter = 0;
    char str;
    char this_is_a_string[10];
    char ch;
    int minimum = 10000; 
    int lowest_One;
    int max = 0;
    int Biggest_One;
    float mean = 0;
    int StreakStart;
    int starter;
    int currentStreak = 0;
    int longestStreak = 0;
    int streakStart = 0;
    int currentStreakStart = 0;

         // array of daily readings
    FITNESS_DATA daily_readings[1000];

    char line[buffer_size];
    char filename[buffer_size];

    while (1)
    {
        printf("A: Input File Name. \n");
        printf("B: Display the total number of records in the file\n");                
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n"); 
        printf("Q: Exit the program\n");                  

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        printf("Choice: %c\n", choice);


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':

    // get filename from the user
        printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
        fgets(line, buffer_size, stdin);
        sscanf(line, " %s ", filename);

            FILE *input = fopen(filename, "r");
            if (!input)
            {
                printf("Error: File could not be opened\n");
                return 1;
            }

            counter = 0; 


            while (fgets(line, buffer_size, input))
            {
            // split up the line and store it in the right place
            // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_readings[counter].date, daily_readings[counter].time, this_is_a_string);

                daily_readings[counter].steps = atoi(this_is_a_string);
            
                counter++;
            }


            break;

        case 'B':
        case 'b':
                
           printf("Total records: %d\n", counter);
            
            break;

        case 'C':
        case 'c':
            for (int i = 0; i < counter; i++)
            {
                if (daily_readings[i].steps < minimum) 
                {
                    minimum = daily_readings[i].steps;
                    lowest_One = i;
                    
                }
            }
            printf("Fewest steps: %s %s\n", daily_readings[lowest_One].date, daily_readings[lowest_One].time);
            break;

        case 'D':
        case 'd':
            for (int i = 0; i < counter; i++)
            {
                if (daily_readings[i].steps > max) 
                {
                    max = daily_readings[i].steps;
                    Biggest_One = i;
                    
                }
            }
            printf("Largest steps: %s %s\n", daily_readings[Biggest_One].date, daily_readings[Biggest_One].time);
            break;

        case 'E':
        case 'e':
            for (int i = 0; i < counter; i++)
            {
                mean += daily_readings[i].steps;
            }
            mean = mean/ counter;

            printf("Mean step count: %.0f\n", mean);
            break;

        case 'F':
        case 'f':
            currentStreak = 0;
            longestStreak = 0;
            streakStart = 0;
            currentStreakStart = -1;  // Initialize to -1 to handle the case where the streak starts at the beginning

            for (int i = 0; i < counter; i++) {
                if (daily_readings[i].steps > 500) {
                    if (currentStreak == 0) {
                        currentStreakStart = i;  // Start of a new streak
                    }
                    currentStreak++;
                } else {
                    if (currentStreak > longestStreak) {
                        longestStreak = currentStreak;
                        streakStart = currentStreakStart;
                    }
                    currentStreak = 0;  // Reset streak if steps are <= 500
                }
            }

            // Check for the last streak
            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
                streakStart = currentStreakStart;
            }

            if (longestStreak > 0) {
                printf("Longest period start: %s %s\n",
                    daily_readings[streakStart].date, daily_readings[streakStart].time);
                printf("Longest period end: %s %s\n",
                    daily_readings[streakStart + longestStreak].date,
                    daily_readings[streakStart + longestStreak].time);
            } else {
                printf("No streak above 500 steps found.\n");
            }
            break;
        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
