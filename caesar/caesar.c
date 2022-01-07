#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool only_digits(string key);

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

    printf("key: %i\n", key);

    string plain = get_string("plaintext:  ");


    //for (int i = 0, n = strlen(plain); i < n; i++)
    //printf("ciphertext: %s\n", cipher);
}

//FUNCTIONS
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
    int cipher = 0;
    if (isalpha(c))
    {
        if (isupper(c))
        {
            cipher = c - A + n;
        }
        else
        {

        }
    }
}

    //printf("%i letters\n", count_letters(text));
    //printf("%i words\n", count_words(text));
    //printf("%i sentences\n", count_sentences(text));