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

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (preferences[i][j] > preferences[j][i])  //candidate_count / voter_count
            {
                pair new_pair;
                new_pair.winner = i;
                new_pair.loser = j;
                pairs[index] = new_pair;
                pair_count++;
                index++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair temp;
    int swap = -1;

    while (swap!= 0)
    {
        for (int i = 0; i < pair_count; i++)
        {
            swap = 0;
            if (pairs[i].winner - pairs.[i].loser) < (pairs[i+1].winner - pairs.[i+1].loser))
            {
                temp = pairs[i];
                pairs[i] = pairs[i+1];
                pairs[i+1] = temp;
                swap++;
            }
        }
        return;
    }
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


}

Alice
Bob
Charlie
Dean

Alice
Bob
Charlie
Dean

Charlie
Dean
Alice
Bob

Dean
Charlie
Bob
Alice

Dean
Charlie
Alice
Bob

pair_count = A&B, A&C, A&D, B&C, B&D, C&D

pairs =
{A - 4      {A - 2      {D - 3      {B - 2      {B - 2
 B - 1} ,    C - 3} ,    A - 2} ,    C - 3} ,    D - 3}

winner pairs =

A - 3       B - 2       C - 3
B - 1  ,    C - 2  ,    D - 2


-------

Alice
Bob
Charlie

Bob
Charlie
Alice

Charlie
Alice
Bob

Charlie
Alice
Bob


A - 3       C - 3       C - 2
B - 1   ,   A - 1   ,   B - 2

printf("Paircount first: %i\n", pair_count);
printf("Paircount: %i\n", pair_count);
printf("pairs sorted\n");
//REMOVE THEN!
    for (int j = 0; j < pair_count; j++)
    {
        printf("winner: %i\n", pairs[j].winner);
        printf("loser: %i\n", pairs[j].loser);
        printf("\n");
    }
    printf("\n");

//REMOVE THEN!

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }
//REMOVE THEN!

//REMOVE THEN!
    // Find winner
    int winner;
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - 1; j++)
        {
            if (winners[i] == losers[j])
            {
                break;
            }
            winner = winners[i];
        }
    }
    //printf("%i", winner);
    //printf("\n");*/

    // Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int edge = 0;
    int limit = pair_count; //pair_count -1;
    int losers[pair_count];
    int winners[pair_count];

    for (int i = 0; i < pair_count; i++) //- 1
    {
        if (edge < limit)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            edge++;
            printf("edge locked %i\n", edge);
            winners[i] = pairs[i].winner;
            losers[i] = pairs[i].loser;
        }
        else //if (edge >= limit)
        {
            int found = 0;
            for (int j = 0; j < edge; j++) // pair_count-1
            {
                // The remaining winner cannot be in the losers list
                if (losers[j] == pairs[i].winner)
                {
                    found = 1;
                }
                /*else
                {
                    // If they are not in the losers list, the arrow(edge) can be added
                    locked[pairs[i].winner][pairs[i].loser] = true;
                    edge++;
                }*/
            }
            if (found == 0)
            {
                printf("winner in losers \n");
                locked[pairs[i].winner][pairs[i].loser] = true;
                winners[i] = pairs[i].winner;
                losers[i] = pairs[i].loser;
                edge++;
                //break;
            }
        }
    }
    return;
}