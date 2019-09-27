#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check if there are 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return (1);
    }
    
    //check if keyword is all letters
    int keyLen = strlen(argv[1]);
    for (int i = 0; i < keyLen; i++)
    {
        if (!isalpha(argv[1][i])) 
        {
             printf("Usage: ./vigenere keyword\n");
             return (1);
        }
        
        if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') 
        {
             argv[1][i] = argv[1][i] + 32;
           
        }
    }
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int strLen = strlen(plaintext);
    int j = 0;
    for (int i = 0; i < strLen; i++)
    {
        int key = argv[1][j]-97;
        int character = plaintext[i];
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
             j++;
        }
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = (plaintext[i] + key % 26);
            if (ciphertext[i] > 'Z')
            {
                ciphertext[i] -= 26;
            }
             j++;
        }
        if (plaintext[i] == ' ') 
        {
            ciphertext[i] = ' ';
        }
       
        if (j==keyLen) {
            j=0;
        }
    }
    printf("ciphertext:\n");
    printf("%s\n", ciphertext);
}