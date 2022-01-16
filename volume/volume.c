// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    int temp_header[HEADER_SIZE];   //allocate memory for header

    // copy header to memory
    fread(&temp_header, sizeof(HEADER_SIZE), 1, input);

    // copy header from memory to new file
    fwrite(&temp_header, sizeof(HEADER_SIZE), 1, output);

    // TODO: Read samples from input file and write updated data to output file
    // allocate memory for 2 int sample
    int16_t temp_sample;

    // copy a sample from file to memory
    while ()
    fread();

    // copy a sample from memory to new file

    // Close files
    fclose(input);
    fclose(output);
}
