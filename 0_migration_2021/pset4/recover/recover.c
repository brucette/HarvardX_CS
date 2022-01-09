#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //if more than 1 command-line argument entered program returns 1 from main
    if (argc != 2)
    {
        printf("Usage: recover filename\n");
        return 1;
    }

    //open file from which jpegs are to be retrieved
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    //512 byte buffer into which the read blocks are stored
    typedef uint8_t BYTE;
    BYTE buffer[512];

    FILE *img;
    int counter = 0;

    char filename[8]; //space for: ###.jpg\0


    while (fread(buffer, sizeof(buffer), 1, file))
    {
        //check header of 512 byte block
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //bitwise arithmetic
        {
            if (counter == 0) //first jpeg
            {
                //create new file to write data to
                sprintf(filename, "%03i.jpg", counter);
                //open new file for writing
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            else
            {
                fclose(img); //file you have been writing to
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
            }
            counter++;
        }
        else
        {
            if (counter > 0)  //already found a jpeg
            {
                fwrite(buffer, sizeof(buffer), 1, img);  //keep writing to it
            }
        }
    }
    fclose(file);
    fclose(img);
}





