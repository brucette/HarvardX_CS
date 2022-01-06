#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);
}

int count_letters(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        
    }
}