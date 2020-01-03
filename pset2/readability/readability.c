// Computes the approximate grade level needed to comprehend some text

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    // Prompt the user for a string of text (using get_string).
    string text = get_string("Text: ");
    int lenString = (unsigned)strlen(text);
    // Loop through string one character at a time
    for (int i = 0; i < lenString; i++)
    {
        // Count the number of letters, a letter is any lowercase character from a to z or any uppercase character from A to Z,
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        // Count the number of words, any sequence of characters separated by spaces should count as a word
        if (text[i] == ' ')
        {
            words++;
        }
        // Count the number of sentences in the text. any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
        if (text[i] == '.' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    // L is the average number of letters per 100 words in the text,
    double L = (double)letters / ((double)words / 100);
    // S is the average number of sentences per 100 words in the text.
    double S = (double)sentences / ((double)words / 100);
    // Coleman-Liau index
    double grade = 0.0588 * L - 0.296 * S - 15.8;

    if (grade >= 16)
    {
        // If the resulting index number is 16 or higher, your program should output "Grade 16+"
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        // Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
        printf("Before Grade 1\n");
    }
    else
    {
        // If the index number is less than 1, your program should output "Before Grade 1".
        printf("Grade %d\n", (int)round(grade));
    }
    return 0;
}