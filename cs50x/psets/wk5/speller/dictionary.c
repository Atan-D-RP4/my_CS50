// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define DICTIONARY "dictionaries/large"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

unsigned int bitwise_sum(int a, int b)
{
    int result = a ^ b;
    int carry = (a & b) << 1;
    if (carry == 0)
        return result;
    else
        return bitwise_sum(carry, result);
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int word_index = hash(word);
    int wordLen = strlen(word);

    node *cursor = table[word_index];
    for (; cursor != NULL; cursor = cursor->next)
    {
        if (wordLen == strlen(cursor->word) && !strcasecmp(word, cursor->word))
            return true;
    }

    return false;

    // Replace the for-loop with
    // return traverse(cursor, word);
    // For a recursive checking of the dictionary
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 5381;
    int len = strlen(word);

    for (int c; (c = *word++);)
    {
        hash_value = (bitwise_sum(hash_value << 2, hash_value)) ^ tolower(c);
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *Dictionary = fopen(dictionary, "r");
    if (Dictionary == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char DictionaryWord[LENGTH + 1];

    while (fscanf(Dictionary, "%s", DictionaryWord) != EOF)
    {
        if (strlen(DictionaryWord) > LENGTH)
            continue;

        // Initialize a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(Dictionary);
            return false;
        }

        // Copy Dictionary Word into new node
        strcpy(new_node->word, DictionaryWord);

        // Hash the word inserted into new node
        unsigned int index = hash(DictionaryWord);
        

        // Insert the new node to the beginning of the Linked list in hash table
        new_node->next = table[index];
        table[index] = new_node;
    }

    fclose(Dictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int totalSize = 0;

    // Iterate over each element of Hash Table Array
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        // Go down the linked list and count nodes
        for (; cursor != NULL; totalSize++, cursor = cursor->next);
    }
    return totalSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        for (; cursor != NULL;)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }

    return true;
}

/* A recursive implementation of list traversal
bool traverse(node* start, const char* word)
{
    if (start == NULL)
        return false;
    if (!strcasecmp(start->word, word))
        return true;

    return traverse(start->next, word);
}
*/
