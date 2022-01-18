#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round(((float)image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int k = width -1;
    RGBTRIPLE buffer;   //buffer for a pixel that is being swapped

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = buffer;
            k--;

            // reset k for next row
            if (k < round((float)width / 2))
            {
                k = width -1;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temp pic for blurred pixels
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalBlue = 0;
            int totalGreen = 0;
            int totalRed = 0;
            int counter = 0;

            // get surrounding pixels coordinates
            int upper_left_i = i - 1;
            int upper_left_j = j - 1;
            int top_i = i - 1;
            int top_j = j;
            int upper_right_i = i - 1;
            int upper_right_j = j + 1;
            int left_i = i;
            int left_j = j - 1;
            int right_i = i;
            int right_j = j + 1;
            int lower_left_i = i + 1;
            int lower_left_j = j - 1;
            int bottom_i = i + 1;
            int bottom_j = j;
            int lower_right_i = i + 1;
            int lower_right_j = j + 1;

            // assign the coordinates to an array so they can be iterated over
            int surround_coords[18] = {i, j, upper_left_i, upper_left_j, top_i, top_j, upper_right_i, upper_right_j,
            left_i, left_j, right_i, right_j, lower_left_i, lower_left_j, bottom_i, bottom_j, lower_right_i, lower_right_j};

            // check if coordinates are out of image range and get rgb values for valid pixels
            for (int k = 0; k < 18; k += 2)
            {
                if (surround_coords[k] >= 0 && surround_coords[k] < height)
                {
                    if (surround_coords[k + 1] >= 0 && surround_coords[k + 1] < width)
                    {
                        int x = surround_coords[k];
                        int y = surround_coords[k + 1];

                        totalBlue += image[x][y].rgbtBlue;
                        totalGreen += image[x][y].rgbtGreen;
                        totalRed += image[x][y].rgbtRed;
                        counter++;
                    }
                }
            }
            int avgBlue = round((float)totalBlue / counter);
            int avgGreen = round((float)totalGreen / counter);
            int avgRed = round((float)totalRed / counter);

            if (avgBlue > 255)
            {
                avgBlue = 255;
            }
            if (avgGreen > 255)
            {
                avgGreen = 255;
            }
            if (avgRed > 255)
            {
                avgRed = 255;
            }

            temp[i][j].rgbtBlue = avgBlue;
            temp[i][j].rgbtGreen = avgGreen;
            temp[i][j].rgbtRed = avgRed;
        }
    }
    // move pixels from temp pic to the original
    for (int l = 0; l < height; l++)
    {
        for (int m = 0; m < width; m++)
        {
            image[l][m] = temp[l][m];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get surrounding pixels coordinates
            int upper_left_i = i - 1;
            int upper_left_j = j - 1;
            int top_i = i - 1;
            int top_j = j;
            int upper_right_i = i - 1;
            int upper_right_j = j + 1;
            int left_i = i;
            int left_j = j - 1;
            int right_i = i;
            int right_j = j + 1;
            int lower_left_i = i + 1;
            int lower_left_j = j - 1;
            int bottom_i = i + 1;
            int bottom_j = j;
            int lower_right_i = i + 1;
            int lower_right_j = j + 1;

            // assign the coordinates to an array so they can be iterated over
            int surround_coords[18] = {i, j, upper_left_i, upper_left_j, top_i, top_j, upper_right_i, upper_right_j,
            left_i, left_j, right_i, right_j, lower_left_i, lower_left_j, bottom_i, bottom_j, lower_right_i, lower_right_j};

            // Gx values
            int Gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};

            // Gy values
            int Gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

            // indices for G values
            int Gxi = 0;
            int Gyi = 0;

            //
            int Blue;
            int Green;
            int Red;

            for (int k = 0; k < 18; k++)
            {
                if (surround_coords[k] >= 0 && surround_coords[k] < height)
                {
                    if (surround_coords[k + 1] >= 0 && surround_coords[k + 1] < width)
                    {
                        int x = surround_coords[k];
                        int y = surround_coords[k + 1];
                        Blue += image[x][y].rgbtBlue;
                        Green += image[x][y].rgbGreen;
                        Red += image[x][y].rgbtRed;
                        

                    }
                }
                else
                {

                }
            }


        }
    }




    return;
}
