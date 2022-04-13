#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 3


int preferences[3][3];
int candidate_count = 3;
typedef struct
{
    int winner;
    int loser;
}
pair;

pair pairs[3 * (3 - 1) / 2];

int pair_count  = 0;

int voter_count = 3;

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (preferences[i][j] > preferences[j][i])  //candidate_count / voter_count
            {
                pair new_pair;
                new_pair.winner = i;
                new_pair.loser = j;
                pairs[j] = new_pair;
                pair_count++;
            }
        }
    }
    return;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}


int main(void)
{
    // ranks[i] is voter's ith preference
    int ranks[] = {2, 1, 0};

    record_preferences(ranks);


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }

    add_pairs();


    for (int j = 0; j < 3; j++)
    {
        printf("%i ", pairs[j]);
    }
    printf("\n");


}