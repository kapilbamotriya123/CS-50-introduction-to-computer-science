#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string names;
    int votes;
} candidate;

candidate candidates[9];
void printwinner(int n);
bool vote(int n, string s);

int main(int argc, string argv[])
{
    if (argc > 10) // argv[0] is the program name, so argc > 10 means more than 9 candidates
    {
        printf("maximum number of candidates exceeded\n");
        return 1;
    }
    if (argc <= 2)
    {
         printf("Usage: ./plurality candidate1 candidate2 ...\n");
         return 1;
    }

    // Initialize candidates
    for (int i = 0; i < argc - 1; i++)
    {
        candidates[i].names = argv[i + 1];
        candidates[i].votes = 0;
    }
    int num_candidates = argc - 1;

    int x = get_int("Total number of voters: ");
    for (int i = 0; i < x; i++)
    {
        string pref = get_string("Vote %i: ", i + 1);
        if (!vote(num_candidates, pref))
        {
            printf("Invalid vote.\n");
        }
    }

    printwinner(num_candidates);
}

bool vote(int n, string s)
{
    // n is the number of candidates
    for (int i = 0; i < n; i++)
    {
        if (strcmp(s, candidates[i].names) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void printwinner(int n)
{
    int max_votes = 0;
    // First, find the highest number of votes
    for (int i = 0; i < n; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }
    // Print all candidates with the highest number of votes
    for (int i = 0; i < n; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].names);
        }
    }
}
