// AVERAGE FOR A FULL PIXEL:
            if (i > 0 && i < height && j > 0 && j < width)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i][j--].rgbtBlue + image[i--][j].rgbtBlue + image[i++][j].rgbtBlue
                + image[i--][j++].rgbtBlue + image[i--][j--].rgbtBlue + image[i++][j--].rgbtBlue + image[i++][j++].rgbtBlue) / 9);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j++].rgbtGreen + image[i][j--].rgbtGreen + image[i--][j].rgbtGreen + image[i++][j].rgbtGreen
                + image[i--][j++].rgbtGreen + image[i--][j--].rgbtGreen + image[i++][j--].rgbtGreen + image[i++][j++].rgbtGreen) / 9);

                int averageRed = round((float)(image[i][j].rgbtRed + image[i][j++].rgbtRed + image[i][j--].rgbtRed + image[i--][j].rgbtRed + image[i++][j].rgbtRed
                + image[i--][j++].rgbtRed + image[i--][j--].rgbtRed + image[i++][j--].rgbtRed + image[i++][j++].rgbtRed) / 9);

                //set temporary pics pixel colors
                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            // MID PIXELS!!
            // AVERAGE FOR A TOP ROW, MID PIXEL:
            if (i == 0 && j > 0 && j < width)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i][j--].rgbtBlue + image[i++][j].rgbtBlue
                + image[i++][j--].rgbtBlue + image[i++][j++].rgbtBlue) / 6);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j++].rgbtGreen + image[i][j--].rgbtGreen + image[i++][j].rgbtGreen
                + image[i++][j--].rgbtGreen + image[i++][j++].rgbtGreen) / 6);

                int averageRed = round((float)(image[i][j].rgbtRed + image[i][j++].rgbtRed + image[i][j--].rgbtRed + image[i++][j].rgbtRed
                + image[i++][j--].rgbtRed + image[i++][j++].rgbtRed) / 6);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            // AVERAGE FOR A BOTTOM ROW, MID PIXEL:
            if (i == height && j > 0 && j < width)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i][j--].rgbtBlue + image[i--][j].rgbtBlue
                + image[i--][j++].rgbtBlue + image[i--][j--].rgbtBlue / 6);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j++].rgbtGreen + image[i][j--].rgbtGreen + image[i--][j].rgbtGreen
                + image[i--][j++].rgbtGreen + image[i--][j--].rgbtGreen / 6);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            // AVERAGE FOR RIGHT ROW, MID PIXEL:
            if (i > 0 && i < height && j == width)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j--].rgbtBlue + image[i--][j].rgbtBlue + image[i++][j].rgbtBlue
                + image[i--][j--].rgbtBlue + image[i++][j--].rgbtBlue / 6);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j--].rgbtGreen + image[i--][j].rgbtGreen + image[i++][j].rgbtGreen
                + image[i--][j--].rgbtGreen + image[i++][j--].rgbtGreen / 6);

                int averageRed = round((float)(image[i][j].rgbtRed + image[i][j--].rgbtRed + image[i--][j].rgbtRed + image[i++][j].rgbtRed
                + image[i--][j--].rgbtRed + image[i++][j--].rgbtRed / 6);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            // AVERAGE FOR LEFT ROW, MID PIXEL:
            if (i > 0 && i < height && j == 0)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i--][j].rgbtBlue + image[i++][j].rgbtBlue
                + image[i--][j++].rgbtBlue + image[i++][j++].rgbtBlue) / 6);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j++].rgbtGreen + image[i--][j].rgbtGreen + image[i++][j].rgbtGreen
                + image[i--][j++].rgbtGreen + image[i++][j++].rgbtGreen) / 6);

                int averageRed = round((float)(image[i][j].rgbtRed + image[i][j++].rgbtRed + image[i--][j].rgbtRed + image[i++][j].rgbtRed
                + image[i--][j++].rgbtRed + image[i++][j++].rgbtRed) / 6);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            //CORNERS!!
            // AVERAGE FOR A TOP ROW, CORNER RIGHT PIXEL:
            if (i == 0 && j == width)
            {

                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j--].rgbtBlue + image[i++][j].rgbtBlue + image[i++][j--].rgbtBlue) / 4);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j--].rgbtGreen + image[i++][j].rgbtGreen + image[i++][j--].rgbtGreen) / 4);

                int averageRed = round((float)(image[i][j].rgbtRed + image[i][j--].rgbtRed + image[i++][j].rgbtRed + image[i++][j--].rgbtRed) / 4);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            // AVERAGE FOR A BOTTOM ROW, CORNER RIGHT PIXEL:
            if (i == height && j == width)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j--].rgbtBlue + image[i--][j].rgbtBlue + image[i--][j--].rgbtBlue) / 4);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j--].rgbtGreen + image[i--][j].rgbtGreen + image[i--][j--].rgbtGreen) / 4);

                int averageRed = round((float)(image[i][j].rgbtRed  + image[i][j--].rgbtRed  + image[i--][j].rgbtRed  + image[i--][j--].rgbtRed ) / 4);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            // AVERAGE FOR A BOTTOM ROW, CORNER LEFT PIXEL:
            if (i == height && j == 0)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i--][j].rgbtBlue + image[i--][j++].rgbtBlue) / 4);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j++].rgbtGreen + image[i--][j].rgbtGreen + image[i--][j++].rgbtGreen) / 4);

                int averageRed = round((float)(image[i][j].rgbtRed + image[i][j++].rgbtRed + image[i--][j].rgbtRed + image[i--][j++].rgbtRed) / 4);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }


            // AVERAGE FOR A TOP ROW, CORNER LEFT PIXEL:
            if (i == 0 && j == 0)
            {
                int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i++][j].rgbtBlue + image[i++][j++].rgbtBlue) / 4);

                int averageGreen = round((float)(image[i][j].rgbtGreen + image[i][j++].rgbtGreen + image[i++][j].rgbtGreen + image[i++][j++].rgbtGreen) / 4);

                int averageRed = round((float)(image[i][j].rgbtRed + image[i][j++].rgbtRed + image[i++][j].rgbtRed + image[i++][j++].rgbtRed) / 4);

                temp[i][j].rgbtBlue = averageBlue;
                temp[i][j].rgbtGreen = averageGreen;
                temp[i][j].rgbtRed = averageRed;
            }
    }
}
