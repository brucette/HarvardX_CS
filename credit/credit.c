#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// MASTERCARD: 16 digits, Start with 51/52/53/54/55
// VISA: 13/16 digits, Start with 4
// AMEX: 15 digits, Start with 34/37


int main(void)
{
    long number = get_long("Number: ");

    char card[17];
    char converted = sprintf(card, "%li", number);
    //printf("*****STRING: %s\n", card);

    int digit;
    int back_sum = 0;
    int remainder_sum = 0;
    char first_set[17];
    char *backwards = malloc((sizeof(char) * 8) + 1);


    int counter = 0;
    do
    {
        // Gets last digit of a number
        digit = number % 10;

        // Get every other digit starting from second last by using counter
        int index = 0;
        if (counter % 2 != 0)
        {

            // Multiply every other number starting from second last by 2
            int num = digit * 2;

            // Convert that integer to string                   //printf("\n CHAR: %s\n", first_set);
            char conv = sprintf(first_set, "%i", num);

            // Concatenate that string to a new variable
            strcat(backwards, first_set);
            //6166618814
            index++;
        }
        else
        {
            // Get sum of the remaining digits
            remainder_sum += digit;
        }
        counter++;
    }
    while (number /= 10);

    printf("FIRST: %s\n", backwards);

    //ADD ALL DIGITS IN first_set together
    for (int i = 0; i < strlen(backwards); i++)
    {
        int again = atoi(backwards[i]);
        back_sum += again;

        printf("BACKSUM: %i\n", back_sum);
        //printf("BACKSUM: %c\n", (int)backwards[i]);
    }

    //CONVERT NUMBER TO STRING AND CHECK FOR LENGTH AND FIRST TWO CHARACTERS

    //char characters[]
    //printf("AMEX\n");
    //printf("MASTERCARD\n");
    //printf("VISA\n");
    //printf("INVALID\n");
    // 371449635398431

}
