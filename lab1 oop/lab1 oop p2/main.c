// Given a file whose number of components is a multiple of four. The file consists
// of non-zero integers, and the number of positive components is equal to the number of negative components.
// Transform the file so that two positive numbers alternate with two negative numbers.

#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    int numbers[100];  // Assuming the file can contain up to 1000 numbers
    int positiveCount = 0, negativeCount = 0, totalCount = 0;
  
    // Open the input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    // Read the numbers from the input file
    while (fscanf(inputFile, "%d", &numbers[totalCount]) != EOF) {
        totalCount++;
    }
    fclose(inputFile);

    // Check if the number of components in the file is divisible by 4
    if (totalCount % 4 != 0) {
        printf("Error: The number of components in the file is not divisible by 4.\n");
        return 1;
    }

    // Iterate through the numbers and modify the sequence
    for (int i = 0; i < totalCount; i += 4) {
        // Alternate two positive numbers with two negative numbers
        numbers[i] = abs(numbers[i]);
        numbers[i + 1] = abs(numbers[i + 1]);
        numbers[i + 2] = -abs(numbers[i + 2]);
        numbers[i + 3] = -abs(numbers[i + 3]);
    }

    // Open the output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Write the modified numbers to the output file
    for (int i = 0; i < totalCount; i++) {
        fprintf(outputFile, "%d ", numbers[i]);
    }
    fclose(outputFile);

    printf("File transformation completed successfully.\n");

    return 0;
}