#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Function prototypes
bool is_valid(string key);


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

    int small_letters[26][26]; //to count number of letters
    //int big_letters[26][26];

    //populate two arrays with capital and small alphabets
    for (int i = 0, j = 'a'; i < 26; i++, j++)
    {
        for (int k = 0; k < 2; k++)
        {
            //big_letters[i][i] = j;
            //big_letters[i][i+1] = 0;
            small_letters[i][i] = j;
            small_letters[i][i+1] = 0;
        }
    }
    /*for (int m = 0; m < 26; m++)
    {
        printf("%c%i\n", big_letters[m][m], big_letters[m][m+1]);
    }*/

    for (int l = 0; l < len; l++)
    {
        if (isalpha(key[l]) == false)
        {
            return false;
            printf("Non alphabetical characters not allowed.");
        }
    }

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
