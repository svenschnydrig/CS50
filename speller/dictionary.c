// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 500000;
// initialise positive hash value using unsigned int
unsigned int hash_value;
// initialise (positive) hash table word count
unsigned int word_count;
// hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    for (node *tmp = table[hash(word)]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
inline int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ tolower(word[i]);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
// open dictionary file
// read strings from file one at a time
// create a new node for each word
// hash word to obtain a hash value
// insert node into hash table at that location

bool load(const char *dictionary)
{
    // TODO

    // open dictionary file
    FILE *file = fopen(dictionary, "r");

    // check whether we were able to open file
    if (file == NULL)
    {
        return false;
    }

    // storage space for word
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
            free(n);
        }
        // Pointer to next node and word itself
        strcpy(n->word, word);
        // Hash the word to get hash value
        hash_value = hash(word);
        // Set new pointer
        n->next = table[hash_value];
        // Set head to new pointer
        table[hash_value] = n;
        // Increment word count
        word_count++;
    }

    // Close file
    fclose(file);
    // If dict is loaded, return true
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // Check if there are any words
    if (word_count > 0)
    {
        // Return count
        return word_count;
    }
    // Else
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Iterate over hash table and free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // Assign cursor
        node *n = table[i];
        // Loop through linked list
        while (n != NULL)
        {
            // Make temp equal cursor;
            node *tmp = n;
            // Point cursor to next element
            n = n->next;
            // free temp
            free(tmp);
        }
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
