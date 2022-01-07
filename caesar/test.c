#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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