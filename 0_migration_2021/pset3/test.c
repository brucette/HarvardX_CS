#include <cs50.h>
#include <stdio.h>
#include <string.h>

//one with only 2 errors:
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        int j = 0;

        if (!candidates[preferences[i][j]].eliminated)
        {
            if (preferences[i][j] != -1)
            {
                candidates[preferences[i][j]].votes++;
                preferences[i][j] = -1;
            }
            j++;
        }
    }
}

void tabulate(void)
{
    bool checked = false;

    for (int i = 0; i < voter_count; i++)
    {
       for (int j = 0; i < voter_count; j++)
        {
            if (!candidates[preferences[i][j]].eliminated)
            {
                if (checked == true)
                {
                    break;
                }
                else if (candidates[preferences[i][j]] != -1)
                {
                    candidates[preferences[i][j]].votes++;
                    preferences[i][j] = -1;
                    checked = true;
                }
            }
        }
    }
   // printf("Index is now: %i\n\n", j);
}








/*int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        //Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}


void tabulate(void)
{

    for (int i = 0, j = 0; i < voter_count; i++)
    {
       if (!candidates[preferences[i][j]].eliminated)
       {
            if (preferences[i][j] != -1)
            {
                candidates[preferences[i][j]].votes++;
                if (preferences[i][j] == preferences[0][j])
                {
                    preferences[i][j] = -1;
                }
            }
            else
            {
                j++;
                if (preferences[i][j] != -1)
                {
                    candidates[preferences[i][j]].votes++;
                    if (preferences[i][j] == preferences[0][j])
                    {
                        preferences[i][j] = -1;
                    }
                }
            }
        }
    printf("Index is now: %i\n\n", j);
    }
}*/






