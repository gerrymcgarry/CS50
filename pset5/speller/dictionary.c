// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
int dict_size = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table

node *table[N];

char dict_word[LENGTH+1];

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return word[0]-97;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 1;
    }
    // Read strings from file one at a time
    while(fscanf(inptr, "%s", dict_word) != EOF)
    {
        dict_size++;
        // Create a new node for each word
        node *new_node = malloc(sizeof(node));
        strcpy(new_node->word, dict_word);
        printf("%s\n", new_node->word );

        // Hash word to obtain hash value
        int index = hash(dict_word);
        // Insert node into hash table at that location
        new_node->next = table[index]->next->next;
        table[index]->next = new_node;

    }


    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
