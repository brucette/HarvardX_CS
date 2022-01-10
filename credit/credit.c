#include <cs50.h>
#include <stdio.h>


int main(void)
{
    long number = get_long("Number: ");

    printf("%li\n", number % 30);

    printf("AMEX\n");
    printf("MASTERCARD\n");
    printf("VISA\n");
    printf("INVALID\n");
}
