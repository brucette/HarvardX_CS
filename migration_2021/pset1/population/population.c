#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int n;

    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);



    // Prompt for end size
    int j;

    do
    {
        j = get_int("End size: ");
    }
    while (j < n);

    printf("%i\n", n);



    // Calculate number of years until we reach threshold
    int years = 0;

    for (; n < j;)
    {
        n = n + (int) n / 3 - (int) n / 4;
        years++;
    }

    // Print number of year
    printf("Years: %i\n", years);

}

