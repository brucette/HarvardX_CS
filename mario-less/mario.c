#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    //request height from user
    do
    {
        height = get_int("Enter height of pyramid: ");
    }
    while (height < 1 || height > 8);

    //To print a left aligned pyramid:
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= i; j++)    //one counter to follow instead of two
        {
            printf("#");
        }
        printf("\n");
    }
        printf("\n");
        
    //Right align the pyramid:
    for (int k = 1; k <= height; k++)
    {
        for (int l = 1; l <= height; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
