#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <strings.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int S = 0; // Size of the dictionary

// Hash table
node *table[N][N][N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int x = hash(word);
    int x0 = x % N;
    int x1 = (x / N) % N;
    int x2 = x / (N * N);

    for (node *ptr = table[x0][x1][x2]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int x0 = toupper(word[0]) - 'A';
    int x1 = (toupper(word[1]) - 'A') * N;
    int x2 = (toupper(word[2]) - 'A') * N * N;
    return x0 + x1 + x2;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(dict, "%45s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            return false;
        }

        int x = hash(word);
        int x0 = x % N;
        int x1 = (x / N) % N;
        int x2 = x / (N * N);

        strcpy(n->word, word);
        n->next = table[x0][x1][x2];
        table[x0][x1][x2] = n;
        S++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return S;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                node *ptr = table[i][j][k];
                while (ptr != NULL)
                {
                    node *tmp = ptr;
                    ptr = ptr->next;
                    free(tmp);
                }
            }
        }
    }
    return true;
}
