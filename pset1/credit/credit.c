#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    // Initialise variables
    char *cardType = "INVALID";
    int total = 0;
    long long num = get_long_long("Credit Card Number: ");
    int numDigits = floor(log10(llabs(num))) + 1;
    int first = num / pow(10, numDigits - 2);
    //Check if number passes formula
    for (int i = 0; i < numDigits; i++)
    {
        if (i % 2)
        {
            int d = num % 10 * 2;
            if (d > 9)submit50 cs50/2018/x/credit
            {
                d = (d - 10) + 1;
            }
            total += d;
        }
        else
        {
            total += num % 10;
        }
        num = num / 10;
    }

    if (first >= 51 && first <= 55 && numDigits == 16 && total % 10 == 0)
    {
        cardType = "MASTERCARD";
    }
    if ((first == 34 || first == 37) && numDigits == 15 && total % 10 == 0)
    {
        cardType = "AMEX";
    }
    if (first >= 40 && first <= 49 && (numDigits == 13 || numDigits == 16) && total % 10 == 0)
    {
        cardType = "VISA";
    }
    printf("%s\n", cardType);
    return (0);
}