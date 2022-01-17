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
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
