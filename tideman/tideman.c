#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check(bool array[MAX][MAX], int x, int y);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Look for the candidate name in the list of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate found, update the ranks and return true. ranks[i] is the voter's ith
        // preference
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    // If no candidate is found, don't update any ranks and return false
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // This will add preferred candidates by 1
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int k = 0;
    // Add each pair of candidates to pairs array if one candidate is preferred over another
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[k].winner = i;
                pairs[k].loser = j;
                k++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[k].winner = j;
                pairs[k].loser = i;
                k++;
            }
        }
    }

    // Update the global variable pair_count to be the total number of pairs
    pair_count = k;
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int j = 0; j < pair_count - 1; j++)
    {
        for (int i = pair_count - 1; i > j; i--)
        {
            int strength1 = preferences[pairs[i].winner][pairs[i].loser] -
                            preferences[pairs[i].loser][pairs[i].winner];
            int strength2 = preferences[pairs[i - 1].winner][pairs[i - 1].loser] -
                            preferences[pairs[i - 1].loser][pairs[i - 1].winner];
            if (strength1 > strength2)
            {
                pair temp = pairs[i - 1];
                pairs[i - 1] = pairs[i];
                pairs[i] = temp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Update locked to create the locked graph by adding all edges in decreasing order of victory
    // strength, as long as there is no cycle.
    for (int i = 0; i < pair_count; i++)
    {
        if (!check(locked, pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int x = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (!locked[j][i])
            {
                x++;
            }
        }
        if (x == candidate_count)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}

bool check(bool array[MAX][MAX], int x, int y)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (array[y][i])
        {
            if (i == x)
            {
                return true;
            }
            if (check(array, x, i))
            {
                return true;
            }
        }
    }
    return false;
}
