#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string text = get_string("Text: ");

    // call functions to count letters, words and sentences
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);


    // calculate L & S
    float L = (letters  /  words) * 100;
    float S = (sentences /  words) * 100;

    // calculate index
    float i = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(i);


    // print grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}


// define count functions
int count_letters(string s)
{
    int count = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string s)
{
    int count = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == ' ')
        {
            count += 1;
        }
    }
    return count + 1;
}

int count_sentences(string s)
{
    int count = 0;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}
