#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Function prototypes
bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
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

    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        rotate(plain[i], key);
    }
}

//FUNCTION DECLARATIONS
bool only_digits(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isdigit(key[i]) == false)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = (c - A + n) % 26;
        }
        else
        {
            c = (c - a + n) % 26;
        }
    }
}
    //printf("%i letters\n", count_letters(text));