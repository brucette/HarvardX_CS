                                                        // to the right                 to the left             on top                      on the bottom
            // AVERAGE FOR A FULL PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i][j--].rgbtBlue + image[i--][j].rgbtBlue + image[i++][j].rgbtBlue
                //top right                 top left                bottom left                 bottom right
            + image[i--][j++].rgbtBlue + image[i--][j--].rgbtBlue + image[i++][j--].rgbtBlue + image[i++][j++].rgbtBlue) / 9;



            // MID PIXELS!!
            // AVERAGE FOR A TOP ROW, MID PIXEL:
             int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i][j--].rgbtBlue /*+ image[i--][j].rgbtBlue*/ + image[i++][j].rgbtBlue
            /*+ image[i--][j++].rgbtBlue + image[i--][j--].rgbtBlue*/ + image[i++][j--].rgbtBlue + image[i++][j++].rgbtBlue) / 6;

            // AVERAGE FOR A BOTTOM ROW, MID PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue + image[i][j--].rgbtBlue + image[i--][j].rgbtBlue /*+ image[i++][j].rgbtBlue*/
            + image[i--][j++].rgbtBlue + image[i--][j--].rgbtBlue /*+ image[i++][j--].rgbtBlue + image[i++][j++].rgbtBlue)*/ / 6;

            // AVERAGE FOR RIGHT ROW, MID PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue /*+ image[i][j++].rgbtBlue*/ + image[i][j--].rgbtBlue + image[i--][j].rgbtBlue + image[i++][j].rgbtBlue
            /*+ image[i--][j++].rgbtBlue*/ + image[i--][j--].rgbtBlue + image[i++][j--].rgbtBlue /*+ image[i++][j++].rgbtBlue)*/ / 6;

            // AVERAGE FOR LEFT ROW, MID PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue /*+ image[i][j--].rgbtBlue*/ + image[i--][j].rgbtBlue + image[i++][j].rgbtBlue
            + image[i--][j++].rgbtBlue /*+ image[i--][j--].rgbtBlue + image[i++][j--].rgbtBlue*/ + image[i++][j++].rgbtBlue) / 6;



            //CORNERS!!                                             // to the right                 to the left             on top                      on the bottom
            // AVERAGE FOR A TOP ROW, CORNER RIGHT PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue /*+ image[i][j++].rgbtBlue*/ + image[i][j--].rgbtBlue /*+ image[i--][j].rgbtBlue*/ + image[i++][j].rgbtBlue
                //top right                 top left                bottom left                 bottom right
            /*+ image[i--][j++].rgbtBlue + image[i--][j--].rgbtBlue*/ + image[i++][j--].rgbtBlue /*+ image[i++][j++].rgbtBlue)*/ / 4;

            // AVERAGE FOR A BOTTOM ROW, CORNER RIGHT PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue + /*image[i][j++].rgbtBlue +*/ image[i][j--].rgbtBlue + image[i--][j].rgbtBlue /*+ image[i++][j].rgbtBlue
            + image[i--][j++].rgbtBlue */+ image[i--][j--].rgbtBlue /*+ image[i++][j--].rgbtBlue + image[i++][j++].rgbtBlue)*/ / 4;

            // AVERAGE FOR A BOTTOM ROW, CORNER LEFT PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue /*+ image[i][j--].rgbtBlue*/ + image[i--][j].rgbtBlue /*+ image[i++][j].rgbtBlue*/
            + image[i--][j++].rgbtBlue /*+ image[i--][j--].rgbtBlue /*+ image[i++][j--].rgbtBlue + image[i++][j++].rgbtBlue)*/ / 4;

             // AVERAGE FOR A TOP ROW, CORNER LEFT PIXEL:
            int averageBlue = round((float)(image[i][j].rgbtBlue + image[i][j++].rgbtBlue /*+ image[i][j--].rgbtBlue + image[i--][j].rgbtBlue*/ + image[i++][j].rgbtBlue
            /*+ image[i--][j++].rgbtBlue + image[i--][j--].rgbtBlue*+ image[i++][j--].rgbtBlue*/ + image[i++][j++].rgbtBlue) / 4;
