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
    // temp pic for edged pixels
    RGBTRIPLE temp[height][width];

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
            int xi = 0;
            int yi = 0;

            //
            int GxBlue = 0;
            int GxGreen = 0;
            int GxRed = 0;

            int GyBlue = 0;
            int GyGreen = 0;
            int GyRed = 0;

            for (int k = 0; k < 18; k += 2)
            {
                if (surround_coords[k] >= 0 && surround_coords[k] < height)
                {
                    if (surround_coords[k + 1] >= 0 && surround_coords[k + 1] < width)
                    {
                        int x = surround_coords[k];
                        int y = surround_coords[k + 1];
                        // get the Gx colours
                        GxBlue += Gx[xi] * image[x][y].rgbtBlue;
                        GxGreen += Gx[xi] * image[x][y].rgbtGreen ;
                        GxRed += Gx[xi] * image[x][y].rgbtRed;
                        xi++;
                        // get the Gy colours
                        GyBlue += Gy[yi] * image[x][y].rgbtBlue ;
                        GyGreen += Gy[yi] * image[x][y].rgbtGreen;
                        GyRed += Gy[yi] * image[x][y].rgbtRed;
                        yi++;
                    }
                }
                else
                {
                    int x = surround_coords[k];
                    int y = surround_coords[k + 1];
                    GxBlue += 0 * Gx[xi];
                    GxGreen += 0 * Gx[xi];
                    GxRed += 0 * Gx[xi];
                    xi++;

                    GyBlue += 0 * Gy[yi];
                    GyGreen += 0 * Gy[yi];
                    GyRed += 0 * Gy[yi];
                    yi++;
                }

                int finalBlue = round(sqrt((GxBlue * GxBlue) + (GyBlue * GyBlue)));
                int finalGreen = round(sqrt((GxGreen * GxGreen) + (GyGreen * GyGreen)));
                int finalRed = round(sqrt((GxRed * GxRed) + (GyRed * GyRed)));

                if (finalBlue > 255)
                {
                    finalBlue = 255;
                }
                if (finalGreen > 255)
                {
                    finalGreen = 255;
                }
                if (finalRed > 255)
                {
                    finalRed = 255;
                }

                temp[i][j].rgbtBlue = finalBlue;
                temp[i][j].rgbtGreen = finalGreen;
                temp[i][j].rgbtRed = finalRed;
            }
        }
    }
    // transfer pixels from temp to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    return;
}
