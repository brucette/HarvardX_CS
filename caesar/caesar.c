#include <cs50.h>
#include <stdio.h>


int main(argc, argv[])
{
    if (argc != 2 || isdigit(argv[1]) == false))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    string plain = get_string("plaintext:  ");

    printf("ciphertext: %s\n", cipher);
}

rintf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));