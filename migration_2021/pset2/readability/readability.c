#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calc_grade(float avgNoLetters, float avgNoSentences);


int main(void)
{

    string text = get_string("Text: "); // get text to be evaluated from user

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);


    // calculate L and S
    float L = ((float) 100 / (float) words) * letters;

    float S = ((float) 100 / (float) words) * sentences;


    int reading = calc_grade(L, S);
}


// FUNCTION FOR CALCULATING LETTERS
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) && (islower(text[i]) || isupper(text[i])))
        {
            letters++;
        }
    }
    return letters;
}


// FUNCTION FOR CALCULATING WORDS
int count_words(string text)
{
    int words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    // add 1 for last word which doesn't have a space after
    words++;
    return words;
}


// FUNCTION FOR CALCULATING SENTENCES
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)    //use ascii numeric values for !, ? and .
        {
            sentences++;
        }
    }
    return sentences;
}


// FUNCTION FOR CALCULATING READING GRADE
int calc_grade(float avgNoLetters, float avgNoSentences)
{
    int grade = round(0.0588 * avgNoLetters - 0.296 * avgNoSentences - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    return 0;
}

