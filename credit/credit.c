#include <cs50.h>
#include <stdio.h>


int lenHelper(long n);

int main(void)
{
    // Amen: starts with 34 or 37, 15 digit
    // MC: 51, 52, 53, 54, or 55, 16 digit
    // Visa: 4, 13 and 16 digit

    long n = get_long("Number: ");

    int length = lenHelper(n);

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        // Calculate checksum
        int sum1 = 0;
        int sum2 = 0;
        long x = n;
        int total = 0;
        int mod1;
        int mod2;
        int d1;
        int d2;

        do
        {
            // Remove last digit and add to sum1
            mod1 = x % 10;
            x = x / 10;
            sum1 = sum1 + mod1;
            // Remove second last digit
            mod2 = x % 10;
            x = x / 10;
            // Double second last digit and add digits to sum2
            mod2 = mod2 * 2;
            d1 = mod2 % 10;
            d2 = mod2 / 10;
            sum2 = sum2 + d1 + d2;
        }
        while (x > 0);

        total = sum1 + sum2;

        // Next check Luhn Algorithm
        if (total % 10 != 0)
        {
            printf("INVALID\n");
            return 0;
        }

        // Get starting digits
        long start = n;
        do
        {
            start = start / 10;
        }
        while (start > 100);

        // Next check starting digits for card type
        if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
        {
            printf("MASTERCARD\n");
        }
        else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
        {
            printf("AMEX\n");
        }
        else if (start / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }


}

int lenHelper(long n)
{
    if (n >= 10000000000000000) return 17;
    if (n >= 1000000000000000)  return 16;
    if (n >= 100000000000000)   return 15;
    if (n >= 10000000000000)    return 14;
    if (n >= 1000000000000)     return 13;
    return 1;
}