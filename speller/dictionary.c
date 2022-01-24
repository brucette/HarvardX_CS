// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <strings.h>


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

int counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // hash word to obtain hash value
    int index = hash(word);

    // access linked list at that index in the hash table
    // traverse linked list, looking for the word
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';
    return (word[0] - 'A' * 26) + (word[1] - 'a') % N;
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
        // hash word to obtain a hash value
        int index = hash(buffer);

        // insert node into hash table at that location
        if (table[index] == NULL)   // first word
        {
            strcpy(table[index]->word, buffer);
            table[index]->next = NULL;
            counter++;
        }
        else
        {*/
        // create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // copy buffer into node
        strcpy(n->word, buffer);
        n->next = NULL;
        counter++;
        n = table[index];
        table[index]->next = n;
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
    for (int i = 0; i < N; i++)
    {                                   //node *cursor = table[i];
        node *cursor = table[i];
        while (cursor != NULL)        //while (cursor != NULL)
        {
            node *tmp = cursor;         //node *tmp = cursor
            cursor = cursor->next;      //cursor = cursor->next
            free(tmp);                  //if (tmp != NULL)
        }
    }                                   //free(tmp)
    return false;                       //return false
}
