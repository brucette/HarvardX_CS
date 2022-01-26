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

unsigned int counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word to obtain hash value
    unsigned int index = hash(word);
    printf("hash is %i\n", index);

    // access linked list at that index in the hash table
    // traverse linked list, looking for the word
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            printf("hash word is %s\n", tmp->word);
            printf("text word is %s\n", word);
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
    if (strlen(word) == 1)
    {
        return ((toupper(word[0]) - 'A' ) * 26) % N;
    }
    return (((toupper(word[0]) - 'A' ) * 26) + (tolower(word[1]) - 'a')) % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    // read strings from the file one at a time
    while (fscanf(dict, "%s", buffer) != EOF) // will return EOF once it reaches the end
    {
        counter++;

        // create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // hash word to obtain a hash value
        unsigned int index = hash(buffer);

        // copy buffer into node
        strcpy(n->word, buffer);
        printf("%s%s\n", table[index]->next->word, table[index]->word);
        if (table[index]->word == NULL)
        {
            n->next = NULL;
            table[index] = n;
        }
        // insert node into hash table at that location
        n->next = table[index];
        table[index] = n;
    }
    fclose(dict);
    //for (int i = 0; i < N; i++)
    //{
        /*if (table[i] != NULL)
        {*/
            //for (node *cursor = table[4]; cursor != NULL; cursor = cursor->next)
            //{
                //printf("===hello\n:");
                //printf("%s\n", table[52]->next->next->next->word);
                //printf("===hello\n:");
            //}
        //}
    //}
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// `s dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            for (node *cursor = table[i]; cursor != NULL; cursor = cursor->next)
            {
                node *tmp = cursor;
                free(tmp);
                tmp = cursor;
                return true;
            }
        }
    }
    return false;
}
