#include <cs50.h>
#include <stdio.h>
#include <string.h>

// MASTERCARD: 16 digits, Start with 51/52/53/54/55
// VISA: 13/16 digits, Start with 4
// AMEX: 15 digits, Start with 34/37

int main(void)
{
    long number = get_long("Number: ");
    int digit;
    int remainder_sum = 0;
    int backwards[16];

    // get every other digit starting from second last:
    int counter = 1;
    do
    {
        digit = number % 10;
        if (counter % 2 == 0)
        {
            printf("backwards: %i\n", digit);
            sum += digit * 2;
        }
        else
        {
            printf("remainders: %i\n", digit);     // get remainder digits sum
            remainder_sum += digit;
        }
        counter++;
    }
    while (number /= 10);

    printf("\n\n");











    /*int multiplier = 100;
    int last_numbs;
    int first_numb;
    int sum = 0;*/

    /*while (number > x) // length of number / 2?
    {
        last_numbs = number % multiplier; // get last digits
        while (last_numbs >= 10)
	    {
		    first_numb = last_numbs / 10;   // then get the first number and add to sum
            sum += first_numb;
            printf("%i\n", first_numb);  //HOW IS THIS SUPPOSED TO WORK???
	    }
        multiplier *= 10;
    }*/



    //string characters;
    //printf("%s\n", (string) number);

    //char characters[]
    //printf("AMEX\n");
    //printf("MASTERCARD\n");
    //printf("VISA\n");
    //printf("INVALID\n");
}
