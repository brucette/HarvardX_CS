void tabulate(void)
{
    // TODO
    for (int i = 0; i < voter_count; i++)
    {
        int j = 0;
        int index = preferences[i][j];
        if (candidates[index].eliminated == false)
        {
            candidates[index].votes++;
        }
        else
        {
            candidates[preferences[i][j + 1]].votes++;
        }
    }
}