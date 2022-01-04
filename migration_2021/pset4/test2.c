#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//void get_coordinates(int y, int x, int height, int width, int image[height][width]);

int main(void)
{
    typedef uint8_t BYTE;
    buffer BYTE[512];

    int counter = 0;
    char *filename = [8]; //###.jpg\0

  while (fread(buffer, sizeof(buffer), 1, argv[1]))
  {
    //check header of 512 byte chucnk
    if (buffer[0]==0xff && buffer[1] == 0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0) //bitwise arithmetic
    {

      if (counter == 0) //first jpeg
      {
        //create new file to write data to
        sprintf(filename, "%03i.jpg", counter);
        //open new file for writing
        FILE *img = fopen(filename, "w");
        fwrite(buffer, sizeof(buffer), 1, filename);
      }
      else
      {
        fclose(img);   //file you have been writing to
        sprintf(filename, "%03i.jpg", counter)
        FILE *img = fopen(filename, "w");
        fwrite(buffer, sizeof(buffer), 1, filename);
      }
      counter++
}
