#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *infile = argv[1];
    int jpg_count = 0;
    char jpg_name[8];
    __uint8_t buffer[512];
    FILE *img;

    // Open memory Card
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // Repeat until end of card
    // Read first 512 bytes into a buffer
    while (fread(&buffer, 512, 1, inptr))
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //         If first JPEG
            if (jpg_count == 0)
            {
                sprintf(jpg_name, "%03d.jpg", jpg_count);
                printf("%s\n", jpg_name);
                img = fopen(jpg_name, "w");
                fwrite(&buffer, 512, 1, img);
            }
            else
            {
                sprintf(jpg_name, "%03d.jpg", jpg_count);
                // printf("%s\n", jpg_name);
                fclose(img);
                img = fopen(jpg_name, "w");
                fwrite(&buffer, 512, 1, img);
            }
            jpg_count++;
        }
        else
        {
            sprintf(jpg_name, "%03d.jpg", jpg_count);
            fwrite(&buffer, 512, 1, img);
        }
    }
    // Close remaining files
    fclose(inptr);
    return 0;
}
