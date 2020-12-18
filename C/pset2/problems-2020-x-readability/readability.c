#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    float l = 0;
    // Starting First Word
    float w = 1;
    float s = 0;
    // Iterate until \0
    for (int i = 0; text[i] != '\0'; i++)
    {
        // If alphabet count 1 to l
        if (isalpha(text[i]) != 0)
        {
            l++;
        }
        // Word Count
        if (isblank(text[i]) == 0 && isblank(text[i - 1]) != 0)
        {
            w++;
        }
        // Sentences Count
        if (text [i] == '.' || text [i] == '?' || text [i] == '!')
        {
            s++;
        }

    }

    // Calculate Grade Using Float
    float letters = (l / w) * 100;
    float sentences = (s / w) * 100;
    float grade = 0.0588 * letters - 0.296 * sentences - 15.8;

    //Make Printf
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(grade));
    }
}