#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Function prototypes
bool is_valid(string key);
char rotate(char c, string key);

int main(int argc, string argv[])
{
    if (argc != 2)  //checks that 1 CL argument is given
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)  //checks that length is 26
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (is_valid(argv[1]) == false) //checks that all are alphabets and no duplicates
    {
        return 1;
    }

    string plain = get_string("plaintext:  ");

    string key = argv[1];

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
            printf("Non alphabetical characters not allowed.\n");
            return false;
        }
    }

    //populate a two dimensional array with the alphabet and a counter for each
    char small_letters[26][26];

    for (int i = 0, j = 'a'; i < 26; i++, j++)
    {
        small_letters[i][0] = j;
        small_letters[i][1] = 0;
    }

    //compare each character in key with the alphabets in the array. Increase alphabets counter by 1 if it exists in key.
    for (int n = 0; n < len; n++)
    {
        for (int p = 0; p < len; p++)
        {
            //use ascii to get 'A'
            if (key[n] == small_letters[p][0] || key[n] == small_letters[p][0] - 32)
            {
                small_letters[p][1] += 1;
            }
        }
    }

    //loop through two dimensional array to get counter result
    for (int i = 0; i < len; i++)
    {
        if (small_letters[i][1] != 1)
        {
            printf("No duplicate characters allowed.\n");
            return false;
        }
    }
    return true;
}

char rotate(char c, string key)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            int index = ((c - 'A') % 26);
            c = toupper(key[index]);
        }
        else
        {
            int index = ((c - 'a') % 26);
            c = tolower(key[index]);
        }
    }
    return c;
}
