#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int sum = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int average = round((float) sum / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    int k = width -1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = buffer;
            k--;

            // resets k for next row
            if (k < round((float)width / 2))
            {
                k = width - 1;
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
            int counter = 0;
            int totalBlue = 0;
            int totalGreen = 0;
            int totalRed = 0;

            // assign surrounding pixels for pixel to be blurred
            int upper_left_i = i -1;
            int upper_left_j = j -1;
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

            // put surrounding pixels into an array so you can iterate over them
            int surround_coords[] = {i, j, upper_left_i, upper_left_j, top_i, top_j, upper_right_i, upper_right_j,
            left_i, left_j, right_i, right_j, lower_left_i, lower_left_j, bottom_i, bottom_j, lower_right_i, lower_right_j};

            // check if any of pixels are outside of the image, collect colors for valid ones
            for (int k = 0; k < 18; k+=2)
            {
                if (surround_coords[k] >= 0 && surround_coords[k] <= height)
                {
                    if (surround_coords[k + 1] >= 0 && surround_coords[k + 1] <= width)
                    {
                        totalBlue += surround_coords[k][k + 1].rgbtBlue;
                        totalGreen += surround_coords[k][k + 1].rgbtGreen;
                        totalRed += surround_coords[k][k + 1].rgbtRed;
                        counter++;
                    }
                }
            }
            int avgBlue = round(totalBlue / counter);
            int avgGreen = round(totalGreen / counter);
            int avgRed = round(totalRed / counter);

            temp[i][j].rgbtBlue = avgBlue;
            temp[i][j].rgbtGreen = avgGreen;
            temp[i][j].rgbtRed = avgRed;

            // move pixels from temp pic to the original

            for (int l = 0; l < height; l++)
            {
                for (int m = 0; m < width; m++)
                {
                    image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
                    image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
                    image[i][j].rgbtRed = temp[i][j].rgbtRed;
                }
            }
        }
    }
    return;
}
