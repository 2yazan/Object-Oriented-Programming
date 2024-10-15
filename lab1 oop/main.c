// A text file contains a sequence of integers. Obtain a typed file of unique numbers from the text file.

#include <stdio.h>
#include <stdlib.h>

#define maxNumbers 1000

void removeDuplicates(const char* inputFileName, const char* outputFileName) {
    // Open the input file in read mode
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return;
    }

    // Create and open the output file in write mode
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Failed to create the output file.\n");
        fclose(inputFile);
        return;
    }

    // const int maxNumbers = 1000; // Maximum number of unique integers
    int numbers[maxNumbers] = {0}; // Fixed-sized array
    int count = 0;
    int number;

    // Read the numbers from the input file
    while (fscanf(inputFile, "%d", &number) == 1) {
        int isDuplicate = 0;

        // Check if the number is already present in the array
        for (int i = 0; i < count; i++) {
            if (numbers[i] == number) {
                isDuplicate = 1;
                break;
            }
        }

        // If it's not a duplicate, add it to the array and write to the output file
        if (!isDuplicate) {
            numbers[count] = number;
            count++;

            fprintf(outputFile, "%d ", number);
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Unique numbers are written to the output file.\n");
}

int main() {
    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.txt";

    removeDuplicates(inputFileName, outputFileName);

    return 0;
}