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

int counter = N;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // hash word to obtain has value
    int index = hash(word);

    // access linked list at that index in the hash table
    node temp = malloc(sizeof(node));

    table[index];
    // traverse linked list, looking for the word(strcasecmp)
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';
    return (word[0] - 'A' * 26) + (word[1] - 'a') % 676;
    /* Az 65 122
    (0) + () = 25
    // Ba 66 97
    (26) + ()
    Bb
    (26) + (1)
    Zz
    (650) + (25) = 675;
    */
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    // read strings from the file one at a time
    while (fscanf(file, "%s", buffer)) // will return EOF once it reaches the end
    {

        if (n == NULL)
        {
            return false;
        }

        // hash word to obtain a hash value
        int index = hash(buffer);

        // insert node into hash table at that location
        if (table[index] == NULL)   // first word
        {
            strcpy(table[index]->word, buffer);
            table[index]->next = NULL;
            //counter++;
        }
        else
        {
            // create a new node for each word
            node *n = malloc(sizeof(node));

            // copy buffer into node
            strcpy(n->word, buffer);
            counter++;
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
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
