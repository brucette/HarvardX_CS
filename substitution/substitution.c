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

    string key = argv[1];




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
//checks that only alphabets and no other characters or duplicates given
bool is_valid(string key)
{
    int len = strlen(key);
    int small_letters['a', 'b', 'c'][3]; //to count number of letters
    int big_letters['A', 'B', 'C'][3];

    for (int i = 0; i < len; i++)
    {
        if (isalpha(key[i]) == false)
        {
            return false;
            printf("Non alphabetical characters not allowed.");
        }
    }

    for (int j = 0; i < len; i++)

        if (key[i] == )
        {
            return false;
            printf("No duplicate characters allowed.");
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
