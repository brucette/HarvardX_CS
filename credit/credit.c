#include <cs50.h>
#include <stdio.h>


int main(void)
{
    long number = get_long("Number ");

    printf("%li", number % 10)

    printf("AMEX\n");
    printf("MASTERCARD\n");
    printf("VISA\n");
    printf("INVALID\n");
}
