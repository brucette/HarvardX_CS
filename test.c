#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 3




int preferences[3][3];

void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (ranks[i] == i)
                {
                    preferences[i][j]++;
                }
            }
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


}