#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// This program checks for the validity of a credit card using Luhn’s Algorithm

int main(void)
{
    long number = get_long("Number: ");

    char card[17];

    // Print whole number as a string and save in card
    char converted = sprintf(card, "%li", number);

    //int digit;
    int remainder_sum = 0;

    // Variable for printing a string to (when converting each digit to string)
    char digit_to_string[3];

    char *backwards = malloc((sizeof(char) * 10) + 1);

    int counter = 0;
    do
    {
        // Gets last digit of a number
        int digit = number % 10;

        // Get every other digit starting from second last by using counter
        if (counter % 2 != 0)
        {

            // Multiply every other number starting from second last by 2
            int num = digit * 2;

            // Convert num to a string
            char conv = sprintf(digit_to_string, "%i", num);

            // Concatenate that string to a new string of all the digits
            strcat(backwards, digit_to_string);
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

    // Add products of the multiplied digits together
    for (int i = 0; i < strlen(backwards); i++)
    {
        int again = backwards[i] - '0';
        back_sum += again;
    }

    // Add sum of remainder digits and products of the multiplied digits together
    int final = back_sum + remainder_sum;

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

    free(backwards);
}




