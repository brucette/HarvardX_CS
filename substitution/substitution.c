#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Function prototypes


int main(int argc, string argv[])
{
    if (argc != 2 || argv[1] != 26) //checks that 1 CL argument is given and its length is 26
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = 0;

    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
    }

    string plain = get_string("plaintext:  ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        printf("%c", rotate(plain[i], key));
    }
    printf("\n");
}

//FUNCTION DECLARATIONS
//checks that it
bool is_valid(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (n == 26)
        {

        }

        if (isdigit(key[i]) == false)
        {
            return ;
        }
    }
    return false;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = ((c - 'A' + n) % 26) + 'A';
        }
        else
        {
            c = ((c - 'a' + n) % 26) + 'a';
        }
    }
    return c;
}
