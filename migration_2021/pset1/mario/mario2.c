#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for height
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);


    // print pyramids
     for (int i = 1; i <= n; i++)
    {
        for (int j = (n - 1); j >= i; j--)
        {
            printf(" ");
        }

        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        for (int l = 1; l <= 2; l++)
        {
            printf("aa");
        }

        for (int m = 1; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}