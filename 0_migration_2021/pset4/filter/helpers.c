#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //get average colour of the pixel and set pixels blue, green and red all to the average color
            int average = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //use provided formula to calculate sepia values for blue, green and red for each pixel
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue =  round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaRed =   round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            //cap at a max of 255 for each color
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            //assign sepia values to each pixel
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int counter = width - 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // divide by 2 to only iterate half way of image
        {
            //temporary pixel to move pixel from original into
            RGBTRIPLE temporary;
            //move pixel from first row first place to temporary pixel
            temporary.rgbtGreen = image[i][j].rgbtGreen;
            temporary.rgbtBlue = image[i][j].rgbtBlue;
            temporary.rgbtRed = image[i][j].rgbtRed;

            //move the pixel from first row last place to first row first place
            image[i][j].rgbtGreen = image[i][counter].rgbtGreen;
            image[i][j].rgbtBlue = image[i][counter].rgbtBlue;
            image[i][j].rgbtRed = image[i][counter].rgbtRed;

            //move pixel from temporary pixel to first row last place pixel
            image[i][counter].rgbtGreen = temporary.rgbtGreen;
            image[i][counter].rgbtBlue = temporary.rgbtBlue;
            image[i][counter].rgbtRed = temporary.rgbtRed;

            counter = counter - 1;

            if (counter < round((float)width / 2))
            {
                counter = width - 1;
            }
        }
    }
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary picture
    RGBTRIPLE temp[height][width];

    //assign the surrounding pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int totalBlue = 0;
            int totalGreen = 0;
            int totalRed = 0;

            int upper_left_x = i - 1;
            int upper_left_y = j - 1;
            int center_top_x = i - 1;
            int center_top_y = j;
            int upper_right_x = i - 1;
            int upper_right_y = j + 1;
            int center_left_x = i;
            int center_left_y = j - 1;
            int center_right_x = i;
            int center_right_y = j + 1;
            int lower_left_x = i + 1;
            int lower_left_y = j - 1;
            int center_bottom_x = i + 1;
            int center_bottom_y = j;
            int lower_right_x = i + 1;
            int lower_right_y = j + 1;

            //put surrounding pixels into an array
            int surround_coords[18] = {upper_left_x, upper_left_y, center_top_x, center_top_y, upper_right_x, upper_right_y, center_left_x, center_left_y, center_right_x, center_right_y,
            lower_left_x, lower_left_y, center_bottom_x, center_bottom_y, lower_right_x, lower_right_y, i, j};

            //check if any of the surrounding pixels is outside of the image, retrieve colours for valid pixels
            for (int k = 0; k < 18; k += 2)
            {
                if (surround_coords[k] >= 0 && surround_coords[k] < height)
                {
                    if (surround_coords[k + 1] >= 0 && surround_coords[k + 1] < width)
                    {
                        int cord_x = surround_coords[k];
                        int cord_y = surround_coords[k + 1];

                        totalBlue += image[cord_x][cord_y].rgbtBlue;
                        totalGreen += image[cord_x][cord_y].rgbtGreen;
                        totalRed += image[cord_x][cord_y].rgbtRed;
                        counter++;
                    }
                }
            }

            //get average colours for pixel
            int averageBlue = round((float)totalBlue / counter);
            int averageGreen = round((float)totalGreen / counter);
            int averageRed = round((float)totalRed / counter);

            if (averageBlue > 255)
            {
                averageBlue = 255;
            }
            if (averageGreen > 255)
            {
                averageGreen = 255;
            }
            if (averageRed > 255)
            {
                averageRed = 255;
            }

            //set temporary picture's pixel colors
            temp[i][j].rgbtBlue = averageBlue;
            temp[i][j].rgbtGreen = averageGreen;
            temp[i][j].rgbtRed = averageRed;
        }
    }

    //move temp images pixels to original
    for (int l = 0; l < height; l++)
    {
        for (int m = 0; m < width; m++)
        {
            image[l][m] = temp[l][m];
        }
    }
}