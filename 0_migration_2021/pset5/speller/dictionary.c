// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;  //allowed to change this to get more buckets

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char temp_word[LENGTH + 1];

    FILE *file= fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s\n", file);
        return false;
    }

    while (file)
    {
        fscanf(file, "%s", temp_word);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return NULL;
        }
        else
        {
            strcpy(temp_word, n->word);
            table[hash(n->word)] = n;   //insert node into hash table
        }
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

