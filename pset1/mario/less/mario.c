#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Recreates this half-pyramid using hashes from Nintendo’s Super Mario Brothers */


int main(void)
{
    char *end;
    char buffer[5];
    int num;

    /* Gets an integer between 0 and 23*/
    do
    {
        printf("Height: ");
        if (!fgets(buffer, sizeof buffer, stdin))
        {
            break;
        }
        buffer[strlen(buffer) - 1] = 0;
        num = strtol(buffer, &end, 10);
    }
    while (end != buffer + strlen(buffer) || num < 1 || num > 8 || strlen(buffer) == 0);

    /* Displays the half Pyramid */
    for (int x = 1; x <= num ; x++)
    {
        for (int y = num; y > 0 ; y--)
        {
            if (y <= x)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return (0);
}