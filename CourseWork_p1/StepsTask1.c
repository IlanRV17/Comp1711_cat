
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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
int main() {

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error to open file.");  
        return 1;
    }

    // Define line counter, records counter and assigned a buffer size 
    int buffer_size = 100;
    char line_buffer[buffer_size];
    int record_counter = 0; 
    char ch;
    int line_counter = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            record_counter++; 
        }
    }

    // Reset the file pointer to the beginning of the file
    // I based this on a discussion with ChatGPT
    // Prompt: Explain how to seek the number of lines in a separete file. 
    fseek(file, 0, SEEK_SET);

    printf("Number of records in file: %d\n", record_counter);

    //Here we assigned date, time and steps their respected values from the file.
    while (fgets(line_buffer, buffer_size, file) != NULL && line_counter < 3) {

        FITNESS_DATA record[21];
        char date[11];
        char time[6];
        char steps[10];

        tokeniseRecord(line_buffer, ",", date, time, steps);
    
    //In this code we called the assigned values and turned them into their respective format.
        if (date != NULL && time != NULL && steps != NULL) {
            printf("%s/%s/%s", date, time, steps);
        } else {
            printf("Error in: %s", line_buffer);
        }
    //Line counter that will determine when to output only three lines.
        line_counter++;
    }

    fclose(file);

    return 0; 

}