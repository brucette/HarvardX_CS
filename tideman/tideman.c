#include <cs50.h>
#include <stdio.h>
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
}
pair;

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

    /*/REMOVE THEN!
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }
    //REMOVE THEN!*/

    add_pairs();

    /*/REMOVE THEN!
    for (int j = 0; j < pair_count; j++)
    {
        printf("%i", pairs[j].winner);
    }
    printf("\n");
    printf("%i", pair_count);
    printf("\n");
    //REMOVE THEN!*/

    sort_pairs();

    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        //compare candidate voter gave to all the candidates running
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
             preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int index = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
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
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair temp;
    int swap = -1;

    while (swap!= 0)
    {
        swap = 0;
        for (int i = 0; i < pair_count - 1; i++)
        {
            // Get strength for current pair
            int winner_votes = preferences[pairs[i].winner][pairs[i].loser];
            int loser_votes = preferences[pairs[i].loser][pairs[i].winner];
            int strength = winner_votes - loser_votes;

            // Get strength for next pair
            int next_winner = preferences[pairs[i+1].winner][pairs[i+1].loser];
            int next_loser = preferences[pairs[i+1].loser][pairs[i+1].winner];
            int next_strength = next_winner - next_loser;

            if (strength < next_strength)
            {
                temp = pairs[i];
                pairs[i] = pairs[i+1];
                pairs[i+1] = temp;
                swap++;
            }
            /*REMOVE THEN!
            printf("%i", winner_votes - loser_votes);
            printf("\n");
            REMOVE THEN!*/
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int edge = 0;
    int limit = pair_count -1;
    int losers[pair_count];
    int winners[pair_count];

    for (int i = 0; i < pair_count - 1; i++)
    {
        if (edge < limit)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            edge++;

            winners[i] = locked[pairs[i].winner];
            losers[i] = locked[pairs[i].loser];
        }
        else if (edge >= limit)
        {
            for (int j = 0; j < pair_count - 1; j++)
            {
                // The remaining winner cannot be in the losers list
                if (losers[j] != locked[pairs[i].winner)
                {
                    break;
                }
            }
            // If they are not in the losers list, the arrow(edge) can be added
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }


    //REMOVE THEN!
    for (int l = 0; l < candidate_count; l++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            printf("%i", locked[j][k]);
            printf("\n");
        }
    }

    // Find winner
    int winner;

    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            printf("%i", locked[j][k]);
            printf("\n");
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}