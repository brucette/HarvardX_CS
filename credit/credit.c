#include <cs50.h>
#include <stdio.h>
#include <string.h>

// MASTERCARD: 16 digits, Start with 51/52/53/54/55
// VISA: 13/16 digits, Start with 4
// AMEX: 15 digits, Start with 34/37

int main(void)
{
    long number = get_long("Number: ");

    int counter = 0;
    do
    {
        int digit = number % 10;
        printf("%i", digit)
    }
    while (number /= 10);

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
    printf("AMEX\n");
    printf("MASTERCARD\n");
    printf("VISA\n");
    printf("INVALID\n");
}
