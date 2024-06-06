#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

// Defines size of each jpeg
#define BLOCK_SIZE 512

// Check if given block of BYTEs is a valid JPEG
bool check_jpeg(BYTE *buffer)
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0);
}

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // Open inputted file
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL) // Check if it is valid in memory
    {
        printf("Could not open inputted IMAGE file");
        return 1;
    }

    FILE *file = NULL; // Output file pointer is initialized
    int i = 0; // No. of files
    BYTE *buffer = malloc(512 * sizeof(BYTE)); // Preparing buffer memory to read into and write from

    // Read Block(512 bytes) sized chunks of data into buffer
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // Check for JPEG
        if (check_jpeg(buffer))
        {
            if (file != NULL)
            {
                fclose(file);
            }

            // Output filename is added
            char filename[10];
            sprintf(filename, "%03d.jpg", i++);

            // Open Output File
            file = fopen(filename, "w");

            // If O/p file is invalid, free all memory used and exit
            if (file == NULL)
            {
                fclose(raw_file);
                free(buffer);
                printf("Could not create output file\n");
                return 1;
            }
        }

        // Check validity of O/p file and write the data of buffer into it
        if (file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, file);
        }
    }

    // Close the O/p file pointer after end of given I/p file is reached
    if (file != NULL)
    {
        fclose(file);
    }

    // Free all space and close all files and exit
    free(buffer);
    fclose(raw_file);
    return 0;
}