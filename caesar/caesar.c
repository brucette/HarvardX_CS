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

    string key = argv[1];
    bool only_digits(string key);

    printf("key: %s\n", key);

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
            return 1;
        }
    }
    return 0;
}
    //printf("%i letters\n", count_letters(text));
    //printf("%i words\n", count_words(text));
    //printf("%i sentences\n", count_sentences(text));