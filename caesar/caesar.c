#include <cs50.h>
#include <stdio.h>


int main(argc, argv[])
{
    if (argc != 2 || isdigit(argv[1]) == false))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    string plaintext = get_string("plaintext:  "
    );
}

rintf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));