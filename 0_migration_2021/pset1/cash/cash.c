#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt user for amount owed

    float n;

    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0.00);


    // convert dollars to cents and set coin counter to 0

    int cents = round(n * 100);

    int coins = 0;


    // substract coins from owed amount

    while (cents > 0)

    {

        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        }


        else if (cents >= 10)
        {
            cents -= 10;
            coins++;
        }


        else if (cents >= 5)
        {
            cents -= 5;
            coins++;
        }


        else if (cents >= 1)
        {
            cents -= 1;
            coins++;
        }

    }

    printf("%i\n", coins);
}