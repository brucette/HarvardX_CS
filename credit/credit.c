#include <cs50.h>
#include <stdio.h>
#include <string.h>

// MASTERCARD: 16 digits, Start with 51/52/53/54/55
// VISA: 13/16 digits, Start with 4
// AMEX: 15 digits, Start with 34/37

int main(void)
{
    long number = get_long("Number: ");

    int last_two = number % 100; //get last two digits

    while (last_two >= 10)
	{
		last_two = last_two / 10;
	}

    printf("%i\n", last_two);//HOW IS THIS SUPPOSED TO WORK???

    //string characters;
    //printf("%s\n", (string) number);

    //char characters[]
    printf("AMEX\n");
    printf("MASTERCARD\n");
    printf("VISA\n");
    printf("INVALID\n");
}
