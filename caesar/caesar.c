#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int k);
bool only_digits(string key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument & make sure every character in argv[1] is a digit
    if (argc != 2 || only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Convert argv[1] from a `string` to an `int`
        int key = atoi(argv[1]);

        // Prompt user for plaintext
        string plaintext = get_string("Plaintext:  ");
        printf("Ciphertext: ");

        // For each character in the plaintext:
        // Rotate the character if it's a letter

        int n = strlen(plaintext);

        for (int i = 0; i < n; i++)
        {
            // printf("Ciphertext: %c\n",
            printf("%c", rotate(plaintext[i], key));
        }
        printf("\n");
    }
}

char rotate(char p, int k)
{
    // Shift c by k positions
    if (islower(p))
    {
        int cipher = ((p - 97 + k) % 26) + 97;
        char c = cipher + 0;
        return c;
    }
    else if (isupper(p))
    {
        int cipher = ((p - 65 + k) % 26) + 65;
        char c = cipher + 0;
        return c;
    }
    else
    {
        return p;
    }
}

bool only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return true;
        }
    }
    return false;
}