#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];

    FILE *file = fopen(infile, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Create a buffer
    BYTE buffer[BLOCK_SIZE];

    // Filename string
    char *filename = malloc(3 * sizeof(int));
    int photoCount = 0;
    FILE *current_jpg = NULL;

    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Check first
            if (photoCount)
            {
                fclose(current_jpg);
            }
            // Generate JPEG file
            sprintf(filename, "%03i.jpg", photoCount);
            current_jpg = fopen(filename, "w");

            photoCount++;
        }
        // If already found
        if (photoCount)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, current_jpg);
        }
    }
    free(filename);
    fclose(current_jpg);
    fclose(file);
    printf("Photos recovered = %i\n", photoCount);
    return 0;
}
