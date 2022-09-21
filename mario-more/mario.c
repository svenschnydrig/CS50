#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // For each row
    for (int i = 0; i < n; i++)
    {
        // For each column dots
        for (int j = 1; j < n - i; j++)
        {
            // Print a space
            printf(" ");
        }
        // For each column bricks
        for (int k = 0; k <= i; k++)
        {
            // Print a brick
            printf("#");
        }
        // For each column fixed two spaces
        for (int l = 0; l < 1; l++)
        {
            // Print a space
            printf("  ");
        }
        // For each column bricks
        for (int k = 0; k <= i; k++)
        {
            // Print a brick
            printf("#");
        }
        // Move to next row
        printf("\n");
    }
}