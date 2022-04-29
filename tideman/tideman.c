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

// REMOVE LATER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (strcmp(argv[1],"-d") == 0)
    {
        printf("debug");
        //return 1;
        candidate_count = 3;
        //candidates[3] = {"Alice", "Bob", "Charlie"};

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i] = argv[i + 2];
        }

        int voter_count = 4;
        pair_count = 0;

        // Clear graph of locked in pairs
        for (int i = 0; i < candidate_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                locked[i][j] = false;
            }
        }

        int ranks1[3] = {0, 1, 2};
        int ranks2[3] = {1, 2, 0};
        int ranks3[3] = {2, 0, 1};
        int ranks4[3] = {2, 0, 1};

        record_preferences(ranks1);
        record_preferences(ranks2);
        record_preferences(ranks3);
        record_preferences(ranks4);

        add_pairs();

        sort_pairs();

        lock_pairs();

        print_winner();
        return 1;
    }
// REMOVE LATER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int edge = 0;
    int final_pair = pair_count -1;
    int losers[pair_count];
    int winners[pair_count];

    for (int i = 0; i < pair_count; i++)
    {
        if (i == 0)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            edge++;
            winners[i] = pairs[i].winner;
            losers[i] = pairs[i].loser;
        }
        if (i > 0 && i < final_pair)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            edge++;
            winners[i] = pairs[i].winner;
            losers[i] = pairs[i].loser;
        }
        if (i == final_pair)//== final_pair - 1)
        {
            int found = 0;
            for (int j = 0; j < edge; j++) // pair_count-1
            {
                // The remaining winner cannot be in the losers list
                if (losers[j] == pairs[i].winner)
                {
                    found = 1;
                }
            }
            if (found == 0)
            {
                locked[pairs[i].winner][pairs[i].loser] = true;
                winners[i] = pairs[i].winner;
                losers[i] = pairs[i].loser;
            }
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winners[MAX];
    int wins = 0;
    int index = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == false)
            {
                printf("one win\n");
                wins++;
            }
        }
        if (wins == candidate_count - 1)
                {
                    winners[index] = i;
                    printf("winner index: %i\n", winners[index]);
                    printf("index: %i\n", index);
                    index++;
                    printf("index now: %i\n", index);
                 }
        wins = 0;
    }

    for (int i = 0; i < index; i++)
    {
        int exists = 0;

        for (int j = 0; j < pair_count; j++)
        {
            if (winners[i] == pairs[j].loser)
            {
                exists = 1;
            }
        }
        if (exists == 0)
        {
            printf("%s", candidates[winners[i]]);
            printf("\n");
        }
    }
    return;
}