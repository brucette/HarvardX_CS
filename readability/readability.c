#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));


    float per_hundred = (float) 100 / count_words(text); //7.14
    printf("%f\n\n", per_hundred);
    float L = (float) count_letters(text) / count_words(text) * per_hundred;    //average number of letters per 100 words
    printf("%f\n\n", L);
    float S = (float) count_sentences(text) / count_words(text) * per_hundred;  //average number of sentences per 100 words
    printf("%f\n\n", S);
    int index = round (0.0588 * L - 0.296 * S - 15.8);

    printf("Grade %i\n", index);

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;      //set to 1 to account for last word after the last space.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')  //(ispunct(text[i]) && text[i] != ',') (isalnum(text[i]) == false && isspace(text[i]) == false && )  (strcmp(&text[i], '.') == 0 || strcmp(&text[i], '?') || strcmp(&text[i], '!'))
        {
            sentences++;
        }
    }
    return sentences;
}