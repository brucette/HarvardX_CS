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


    // Iterate from 1 and print number of hashes 

    for (int i = 1; i <= n; i++)
    {
        for (int k = (n - 1); k >= i; k--)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}