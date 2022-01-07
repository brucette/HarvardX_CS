#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


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

bool is_valid(string key)
{
    int len = strlen(key);

    int small_letters[26][26]; //to count number of letters
    int big_letters[26][26];

    for (int i = 0, k = 0; i < 26; i++, k++)
    {
        for (int j = 65; j < 91; j++)
        {
            big_letters[i] = j;
            big_letters[k] = 0;
            small_letters[i] = j + 32;
            small_letters[k] = 0;
        }
    }