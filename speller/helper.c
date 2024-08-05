#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

const unsigned int LENGTH = 45;
unsigned int hash(const char *word);
bool load(const char *dictionary);

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;


unsigned int S = 0; //size of the dictionary

// Hash table
node *table[N][N][N];

int main()
{
    if (load("/workspaces/127962702/speller/dictionaries/small"))
    {
        printf("loaded\n");
        printf("%s\n", table[2][0][19] -> word);
    }
}


unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int x0 = toupper(word[0]) - 'A';
    int x1 = (toupper(word[1]) - 'A')*100;
    int x2 = (toupper(word[2]) - 'A')*10000;
    return x0 + x1 + x2; //that should give an int such that x%100 = w[0], x/100 = w[1]
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                table[i][j][k] = NULL;
            }
        }
    }


    //Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    char word[LENGTH + 1];
    if (dict == NULL)
    {
        return false;
    }
    while(fscanf(dict, "%45s", word) == 1)
    {
        printf("Read word: %s\n", word);
        int x = hash(word);
        int x0 = x%10000;
        int x1 = (x/100)%100;
        int x2 = x/10000;

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }
        strcpy(n-> word,word);

        n -> next = table[x0][x1][x2] ;
        table[x0][x1][x2]  = n;
        S++;

    }
    fclose(dict);
    return true;
}
