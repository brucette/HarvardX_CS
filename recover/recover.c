#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf()
        return 1;
    }

    int counter = 0;
    int buffer = 

    //open file for reading ("coping")
    FILE *card = fopen(argv[1],"r");

    // keep reading 512 byte chunks into a buffer
    while (fread(buffer))
        // check if first 4 bytes are start of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 == 0xe0))
        {

        }

        // if so, copy byte into a new file name ###.jpg
        sprintf(filename, "%03i.jpg", no.(counter))

        // open new file and write (paste) the byte into it
        FILE *img = fopen();
}