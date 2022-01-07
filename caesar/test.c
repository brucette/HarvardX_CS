#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    string key = argv[1];

    int len = strlen(key);

    char small_letters[26][26]; //to count number of letters
    char big_letters[26][26];

    for (int i = 0, k = 0; i < 26; i++, k++)
    {
        for (char j = 'A'; j < 'Z'; j++)
        {
            strcpy(&j, big_letters[i]);
            strcpy(0, big_letters[k]);
            //big_letters[k] = 0;
            small_letters[i] = j + 32;
            small_letters[k] = 0;
        }
    for (int m = 0; m < 26; m++)
    {
        printf("%c%i", big_letters[m][m]);
    }
}