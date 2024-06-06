#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int string_counts(string text, int c);
void grade_level(string text);

int main(void)
{
    // Prompt User for Text string
    string text = get_string("Text: ");
    // Find out Grade Level of text and Print it
    grade_level(text);
    return 0;
}

int string_counts(string text, int c)
{
    int letters = 0, words = 1, sentences = 0;
    // Iterate over each element of the text
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Count letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Count words
        else if (text[i] == ' ')
        {
            words++;
        }
        // Count Sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

    }
    if (c == 1)
    {
        return letters;
    }
    else if (c == 2)
    {
        return words;
    }
    else if (c == 3)
    {
        return sentences;
    }
    else
    {
        return 0;
    }
}

void grade_level(string text)
{
    float letters = string_counts(text, 1), words = string_counts(text, 2), sentences = string_counts(text, 3);
    // Compute Coleman-Liau Index
    float index = (0.0588 * ((letters / words) * 100)) - (0.296 * ((sentences / words) * 100)) - 15.8;
    // Print Out Grade Level
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}