#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change = -1;
    while (change < 0)
    {
        change = get_float("Change owed: ");
    }
    int cents = round(change * 100);
    int quarters = cents / 25;
    cents = cents - quarters * 25;
    int dimes = cents / 10;
    cents = cents - dimes * 10;
    int nickels = cents / 5;
    cents = cents - nickels * 5;
    int pennies = cents;
    int total = quarters + dimes + nickels + pennies;
    printf("%d\n", total);
}