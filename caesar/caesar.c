#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //|| isdigit(argv[1]) == false))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    string key = argv[1];
    printf("key: %i", key);

    string plain = get_string("plaintext:  ");


    //for (int i = 0, n = strlen(plain); i < n; i++)
    //printf("ciphertext: %s\n", cipher);
}

    //printf("%i letters\n", count_letters(text));
    //printf("%i words\n", count_words(text));
    //printf("%i sentences\n", count_sentences(text));