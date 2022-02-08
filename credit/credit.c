#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// MASTERCARD: 16 digits, Start with 51/52/53/54/55

int main(void)
{
    long number = get_long("Number: ");

    char card[17];
    char converted = sprintf(card, "%li", number);

    int digit;
    int remainder_sum = 0;
    char first_set[17];
    //char *backwards = malloc((sizeof(char) * 10) + 1);
    char backwards[12];

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

            // Convert that integer to string
            char conv = sprintf(first_set, "%i", num);

            // Concatenate that string to a new variable
            strcat(backwards, first_set);
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

    int back_sum = 0;
    //int back_sum = atoi(backwards);
    //int back_sum = backwards[0] - '0';
    //printf("FIRST: %s\n", backwards);
    //printf("FIRST: %i\n", back_sum);

    // Add products of the multiplied digits together
    for (int i = 0; i < strlen(backwards); i++)
    {
        int again = backwards[i] - '0';
        back_sum += again;
    }

    // Add sum of remainder digits and products of the multiplied digits together
    int final = back_sum + remainder_sum;
    //printf("FINALSUM: %i\n", final);

    int length = strlen(card);

    // Check if 0 exists in end sum by using % 10
    if (final % 10 == 0)
    {
        // Check for valid length and first two characters
        if (card[0] == '4' && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else if (card[0] == '5' && card[1] >= '1' && card[1] <= '5' && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (card[0] == '3' && (card[1] == '4' || card[1] == '7') && length == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}




