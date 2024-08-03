#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "rb");
    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open forensic image file for reading.\n");
        return 1;
    }

    FILE *jpeg_file = NULL;
    int jpeg_count = 0;

    BYTE buffer[BLOCK_SIZE];

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg_file != NULL)
            {
                fclose(jpeg_file);
            }

            char filename[12];
            sprintf(filename, "%03d.jpg", jpeg_count);
            jpeg_file = fopen(filename, "wb");
            if (jpeg_file == NULL)
            {
                fprintf(stderr, "could not create JPEG file.\n");
                return 1;
            }
            jpeg_count++;
        }
        if (jpeg_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpeg_file);
        }
    }
    if (jpeg_file != NULL)
    {
        fclose(jpeg_file);
    }

    fclose(raw_file);

    return 0;
}
