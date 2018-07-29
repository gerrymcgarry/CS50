#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, const char *args[])
{
    if (argc != 2)
    {
        printf("Error - Not valid input\n");
        return (1);
    }
    int key = atoi(args[1]);
    //printf("%s %d-\n", args[1], key);
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int strLen = strlen(plaintext);
    for (int i = 0; i < strLen; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            int newKey = key % 26;
            if (plaintext[i] + newKey - 97 > 26)
            {
                newKey -= 26;
            }
            ciphertext[i] = (plaintext[i] + newKey);
            if (ciphertext[i] > 'z')
            {
                ciphertext[i] = ciphertext[i] - 26;
            }
        }
        cd if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = (plaintext[i] + key % 26);
            if (ciphertext[i] > 'Z')
            {
                ciphertext[i] -= 26;
            }
        }
    }
    printf("ciphertext:\n");
    printf("%s\n", ciphertext);
    return (0);
}