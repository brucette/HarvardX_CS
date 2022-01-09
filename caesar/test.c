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
    //int big_letters[26][26];

    for (int i = 0, j = 'a'; i < 26; i++, j++)
    {
        for (int k = 0; k < 2; k++)
        {
            //big_letters[i][i] = j;
            //big_letters[i][i+1] = 0;
            small_letters[i][i] = j; //+ 32;
            small_letters[i][i+1] = 0;
        }
    }
    for (int m = 0; m < 26; m++)
    {
        printf("%c%i\n", small_letters[m][0], small_letters[m][1]);
    }
}