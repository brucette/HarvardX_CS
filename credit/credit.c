#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// MASTERCARD: 16 digits, Start with 51/52/53/54/55
// VISA: 13/16 digits, Start with 4
// AMEX: 15 digits, Start with 34/37
// 371449635398431

int main(void)
{
    long number = get_long("Number: ");

    int digit;
    int remainder_sum = 0;
    //int first_set[8];
    char first_set[3];
    char backwards[17];
    //string num [8];


    int counter = 0;
    do
    {
        digit = number % 10;    // gets last digit of a number
        int index = 0;
        if (counter % 2 != 0)
        {
            printf("*****backwards: %i\n", digit);    // get every other digit starting from second last

            int num = digit * 2;    // multiply every other number starting from second last by 2

            //char conv = printf("%i", num);
            sprintf(first_set, "%i", num); // converts integer to string
            printf("\n CHAR: %s\n", first_set);

            //strcpy(backwards, &conv);
            //printf("#####FIRST_SET: %c\n", first_set[index]);
            index++;

//strcpy((char)conv, backwards);
// how to then add those digits to another long/int array/char array,how to convert int to string?
        }
        else
        {
            printf("remainders: %i\n", digit);     // get remaining digits sum
            remainder_sum += digit;
        }
        counter++;
    }
    while (number /= 10);


    //ADD ALL DIGITS IN first_set together (use isdigit()?)
    //CONVERT NUMBER TO STRING AND CHECK FOR LENGTH AND FIRST TWO CHARACTERS



    /*for (int i = 0; i < 8; i++)
    {
        printf("BACKWARDS: %s\n", backwards);
    }*/

    /*printf("FIRST SET: %i\n", first_set[1]);
    printf("FIRST SET: %i\n", first_set[2]);
    printf("FIRST SET: %i\n", first_set[3]);
    printf("FIRST SET: %i\n", first_set[4]);
    printf("FIRST SET: %i\n", first_set[5]);
    printf("FIRST SET: %i\n", first_set[6]);
    printf("FIRST SET: %i\n", first_set[7]);
    printf("\n\n");*/


    //string characters;
    //printf("%s\n", (string) number);

    //char characters[]
    //printf("AMEX\n");
    //printf("MASTERCARD\n");
    //printf("VISA\n");
    //printf("INVALID\n");

}
