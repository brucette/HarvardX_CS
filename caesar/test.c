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

    for (int i = 0, k = 0; i < 26; i++, k++)
    {
        for (int j = 'A'; j < 'Z'; j++)
        {
            //strcpy(j, big_letters[i]);
            strcpy(0, big_letters[k]);
            //big_letters[k] = 0;
            strcpy(&j+32, small_letters[i]);
            strcpy(0, small_letters[k]);
            //small_letters[i] = j + 32;
            //small_letters[k] = 0;
        }
    }
    for (int m = 0; m < 26; m++)
    {
        printf("%c", big_letters[m][m]);
    }
}