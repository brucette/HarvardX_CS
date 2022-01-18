#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf()
        return 1;
    }

    int counter = 0;
    BYTE buffer[512];

    //open file for reading ("coping")
    FILE *card = fopen(argv[1],"r");

    // keep reading 512 byte chunks into a buffer
    while (fread(buffer, sizeof(buffer), 1, card))
    {
        // check if first 4 bytes are start of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 == 0xe0) && counter )
        {
            if (counter > 0)
            {
                // if so, copy byte into a new file name ###.jpg
                sprintf(filename, "%03i.jpg", counter)
            }
        }

    }




        // open new file and write (paste) the byte into it
        FILE *img = fopen();
}