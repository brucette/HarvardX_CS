#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    string key = argv[1];

    int len = strlen(key);

    int small_letters[26][26]; //to count number of letters
    int big_letters[26][26];

    for (int i = 0; i < 26; i++)
    {
        for (int j = 'A'; j < 'Z'; j++)
        {
            big_letters[i][i] = j;
            big_letters[i][i+1] = 0;
            small_letters[i][i] = j + 32;
            small_letters[i][i+1] = 0;
        }
    }
    for (int m = 0; m < 26; m++)
    {
        for (int l = 0; l < m; l++)
        {
            printf("%c%i\n", big_letters[m][m], big_letters[m][m+1]);
        }
    }
}