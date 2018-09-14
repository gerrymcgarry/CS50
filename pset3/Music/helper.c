// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
#include <string.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int duration = (atoi(&fraction[0]) * 8 / atoi(&fraction[2]));
    return duration;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char lookup[3][12] =
    {
        {'C', '-', 'D', '-', 'E', 'F', '-', 'G', '-', 'A', '-', 'B'},
        {'-', 'C', '-', 'D', '-', '-', 'F', '-', 'G', '-', 'A', '-'},
        {'-', 'D', '-', 'E', '-', '-', 'G', '-', 'A', '-', 'B', '-'}
    };
    int row = 0;
    char octave = atoi(&note[1]);
    int key = 0;
    if (note[1] == '#')
    {
        row = 1;
        octave = atoi(&note[2]);
    }
    else if (note[1] == 'b')
    {
        row = 2;
        octave = atoi(&note[2]);
    };

    for (int i = 0; i < 12; i++)
    {
        if (note[0] == lookup[row][i])
        {
            key = i;
        }
    }

    int test = octave * 12 + key - 57;
    int freq = round(pow(2, (double)test / 12) * 440);
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s, "", 1))
    {
        return false;
    }
    return true;
}
