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
    int index = hash(word);
    //printf("hash is %i\n", index);
    //printf("word length is %lu\n", strlen(word));

    // access linked list at that index in the hash table
    // traverse linked list, looking for the word

    //printf("INDEX BEGIN IS****%s*****\n", table[index]->next->next->word);

    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
                                                                    //printf("hash word is %s\n", tmp->word);
                                                                    //printf("text word is %s\n", word);
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
        int index = hash(buffer);

        // copy buffer into node
        strcpy(n->word, buffer);
                                                                           //printf("BUFFER IS ****%s*****\n\n", buffer);
                                                                            //printf("INDEX BEGIN IS****%s*****\n", table[index]->word);
        //if (table[index] == NULL)
        //{
            //n->next = NULL;
            //table[index] = n;
        //}
        // insert node into hash table at that location
        n->next = table[index];
        table[index] = n;
    }
    fclose(dict);
    return true;
}

/*void see(void)
{
    for (node *cursor = table[52]; cursor != NULL; cursor == cursor->next)
    {
        //printf("===hello\n:");
        printf("%s\n", table[52]->word);
        //printf("===hello\n:");
    }
}*/

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
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return false;
}

/*while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    return 0;*/
