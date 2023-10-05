#include "cs50.h"
#include <math.h>
#include <stdio.h>

int get_words(string);
float get_letters_per_words(string, int);
float get_sentencees_per_words(string, int);

int main(void)
{
    string s = get_string("please enter a string : ");

    int words = get_words(s);
    float lettersPer100 = get_letters_per_words(s, words);
    float sentencPer100 = get_sentencees_per_words(s, words);
    int index = round((0.0588 * lettersPer100) - (0.296 * sentencPer100) - 15.8);
    if (index < 0)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %i\n", index);
}

int get_words(string s)
{
    int words = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
            words++;
    }
    return ++words;
}

float get_letters_per_words(string s, int words)
{
    int letters = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            letters++;
    }
    return (float)letters / (float)words * 100;
}

float get_sentencees_per_words(string s, int words)
{
    int sentences = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '.':
        case '?':
        case '!':
            sentences++;
            break;
        }
    }
    return (sentences / (float)words) * 100;
}