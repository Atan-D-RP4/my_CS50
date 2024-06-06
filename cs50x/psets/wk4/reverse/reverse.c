#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

const int HEADER_SIZE = 44;

int check_format(WAVHEADER header)
{
    // TODO #4
    BYTE valid_format[4] = {'W', 'A', 'V', 'E'};
    int match = 0;

    for(int i = 0; i < 4; i++)
    {
        if (valid_format[i] == header.format[i])
        {
            match++;
        }
    }

    if (match == 4)
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = header.numChannels * (header.bitsPerSample / 8);
    return block_size;
}

int main(int argc, char *argv[])
{
    // TODO #1
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav");
        return 1;
    }

    // TODO #2
    // Open input file for reading
    FILE *infile = fopen(argv[1], "rb");
    if (infile == NULL)
    {
        printf("Could not open i/p file.\n");
        return 1;
    }

    // TODO #3
    // Read header
    WAVHEADER header;
    fread(&header, HEADER_SIZE, 1, infile);

    // TODO #4
    // Use check_format to ensure WAV format
    if (!check_format(header))
    {
        printf("Given i/p file is not valid .wav file\n");
        fclose(infile);
        return 3;
    }

    if (header.audioFormat != 1)
    {
        printf("Given i/p file is not valid .wav file\n");
        fclose(infile);
        return 3;
    }

    // TODO #5
    // Open output file for writing
    FILE *outfile = fopen(argv[2], "wb");
    if (outfile == NULL)
    {
        printf("Could not open o/p file.\n");
        return 2;
    }

    // TODO #6
    // Write header to file
    fwrite(&header, HEADER_SIZE, 1, outfile);

    // TODO #7
    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);


    // TODO #8
    // Write reversed audio to file
    BYTE *buffer = malloc(sizeof(BYTE) * block_size);
    fseek(infile, block_size, SEEK_END);
    while(ftell(infile) - block_size > HEADER_SIZE)
    {
        fseek(infile, -2 * block_size, SEEK_CUR);
        fread(buffer, block_size, 1, infile);
        fwrite(buffer, block_size, 1, outfile);
    }

    // Close all opened files and free all allocated memory and exit
    fclose(outfile);
    fclose(infile);
    free(buffer);
    return 0;
}