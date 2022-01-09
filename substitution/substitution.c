#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Function prototypes
bool is_valid(string key);


int main(int argc, string argv[])
{
    if (argc != 2)  //checks that 1 CL argument is given
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argv[1] != 26)  //checks that length is 26
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (is_valid(argv[1]) == false) //checks that all are alphabets and no duplicates
    {
        return 1;
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

bool is_valid(string key)
{
    int len = strlen(key);
    //checks that only alphabets and no other characters given
    for (int l = 0; l < len; l++)
    {
        if (isalpha(key[l]) == false)
        {
            printf("Non alphabetical characters not allowed.");
            return false;
        }
    }
    //populate a two dimensional array with the alphabet and a counter for each
    int small_letters[26][26];

    for (int i = 0, j = 'a'; i < 26; i++, j++)
    {
        for (int k = 0; k < 2; k++)
        {
            small_letters[i][i] = j; //+ 32;
            small_letters[i][i+1] = 0;
        }
    }

    //compare aech character if it matches with any of the alphabets in the array. Increase alphabets counter if it does
    for (int m = 0; m < 1; m++)
    {
        for (int n = 0; n < len; n++)
        {
            if (key[m] == big_letters[n][0])
            {
                big_letters[n][1] += 1;
            }
            if (key[m] == small_letters[n][0])
            {
                small_letters[n][1] += 1;
            }
        }
    }
    //return false;
    //printf("No duplicate characters allowed.");

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
