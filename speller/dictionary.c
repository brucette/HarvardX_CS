// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

#include <stdlib.h>
#include <stdio.h>



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

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
    // TODO: Improve this hash function
    word[0]
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s\n", dictionary);
        return false;
    }

    char buffer[LENGTH + 1];

    int counter = 0;

    // read strings from the file one at a time
    while (fscanf(file, "%s", buffer)) // will return EOF once it reaches the end
    {
        // create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // hash word to obtain a hash value
        int index = hash(buffer);
        // copy buffer into node
        strcpy(n->word, buffer);
        // insert node into hash table at that location
        if (counter == 0)   // first word
        {
            table[index]->next = n;
            n->next = NULL;
            counter++;
        }
        else
        {
            n->next = table[index];
            table[index]->next = n;
        }
    }
    return true;
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
