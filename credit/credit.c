#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    long number = get_long("Number: ");

    printf("%li\n", number % 10);//HOW IS THIS SUPPOSED TO WORK???

    string characters;
    printf("%s\n", (string) number);

    //char characters[]
    printf("AMEX\n");
    printf("MASTERCARD\n");
    printf("VISA\n");
    printf("INVALID\n");
}
