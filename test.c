#include <cs50.h>
#include <stdio.h>

// Max number of candidates
#define MAX 3

// ranks[i] is voter's ith preference
int ranks[] = {2, 1, 0};

int preferences[3][3];

void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ranks[i] == preferences[j])
            {
                preferences[i][j]++
            }
        }
    }
    return;
}


int main(void)
{

    record_preferences(ranks);


}